#include <Arduino.h>

#include "PancakePrinter.h"

PancakePrinter::PancakePrinter() :
    _topMotorShield{TOP_MOTOR_SHIELD_ADDR},
    _botMotorShield{BOT_MOTOR_SHIELD_ADDR},
    _xStepper{_topMotorShield.getStepper(Gantry::STEPS_PER_REV, X_STEPPER_PORT)},
    _yStepper{_topMotorShield.getStepper(Gantry::STEPS_PER_REV, Y_STEPPER_PORT)},
    _pumpMotor{_botMotorShield.getMotor(PUMP_MOTOR_PORT)},
    _solenoidMotor{_botMotorShield.getMotor(SOLENOID_MOTOR_PORT)},
    _griddle{GRIDDLE_PIN},
    _gantry{_xStepper, _yStepper},
    _extruder{_pumpMotor, _solenoidMotor},
    _commandQueue{10} {
}

PancakePrinter::~PancakePrinter() {
    finish();
}

// Listen for recipes over serial
// and run them as they come.
void PancakePrinter::listen() {

    // ensure serial is ready
    while (!Serial) {
        delay(10);
    }

    Serial.println("listen()");

    while (true) {
        if (Serial.available() > 0) {
            String command = _commandCourier.readCommand();
            if (command.compareTo(BEGIN_RECIPE) == 0) {
                listenForRecipe();
            }
        }
        release();
    }

}

void PancakePrinter::release() {
    _gantry.release();
}

void PancakePrinter::listenForRecipe() {
    // keep executing commands until
    // we read the 'DONE' command
    bool done = false;
    bool commandsPending = false;
    while (!done) {
        if (Serial.available() > 0) {
            commandsPending = false;

            String command = _commandCourier.readCommand();
            if (command.compareTo(DONE_COMMAND) == 0) {
                done = true;
            } else {
                run(command);
            }
        } else if (!commandsPending) {
            _commandCourier.requestCommands();
            commandsPending = true;
        }
    }

    finish();
    Serial.println("Done!");
}

void PancakePrinter::finish() {
    extrudeOff();
    setTemperature(0);
    moveTo(0, 0);
}

void PancakePrinter::run(String commandStr) {
    PrinterCommand *command = _interpreter.interpret(commandStr);
    switch (command->type()) {
        case PrinterCommandType::MOVE:
            runMoveCommand((PrinterMoveCommand *) command);
            break;
        case PrinterCommandType::TEMP:
            runTempCommand((PrinterTempCommand *) command);
            break;
        case PrinterCommandType::EXTRUDE:
            runExtrudeCommand((PrinterExtrudeCommand *) command);
            break;
        case PrinterCommandType::DELAY:
            runDelayCommand((PrinterDelayCommand *) command);
            break;
        case PrinterCommandType::HOME:
            runHomeCommand((PrinterHomeCommand *) command);
            break;
    }
    delete command;
}

void PancakePrinter::runMoveCommand(PrinterMoveCommand *command) {
    moveTo(command->getX(), command->getY());
}

void PancakePrinter::runTempCommand(PrinterTempCommand *command) {
    setTemperature(command->getTemperature());
}

void PancakePrinter::runExtrudeCommand(PrinterExtrudeCommand *command) {
    if (command->extrude()) {
        extrudeOn();
    } else {
        extrudeOff();
    }
}

void PancakePrinter::runDelayCommand(PrinterDelayCommand *command) {
    delay(command->getDelay());
}

void PancakePrinter::runHomeCommand(PrinterHomeCommand *command) {
    moveTo(0, 0);
}

void PancakePrinter::init() {
    _topMotorShield.begin();
    _botMotorShield.begin();
    _griddle.init();

}

void PancakePrinter::calibrate() {
    // find the min/max travel dimensions
    _gantry.calibrate();
}

void PancakePrinter::moveTo(float x, float y) {
    _gantry.moveTo(x, y);
}

void PancakePrinter::setTemperature(float temp) {
    _griddle.setTemperature(temp);
}

void PancakePrinter::extrudeOn() {
    _extruder.extrudeOn();
}

void PancakePrinter::extrudeOff() {
    _extruder.extrudeOff();
}

const String PancakePrinter::DONE_COMMAND = "D";
const String PancakePrinter::BEGIN_RECIPE = "BEGIN RECIPE";
const String PancakePrinter::READY = "READY";
