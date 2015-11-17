#include <Arduino.h>

#include "PancakePrinter.h"

PancakePrinter::PancakePrinter() :
    _topMotorShield{0x61},
    _botMotorShield{0x60},
    _xStepper{_topMotorShield.getStepper(200, 1)},
    _yStepper{_topMotorShield.getStepper(200, 2)},
    _pumpMotor{_botMotorShield.getMotor(2)},
    _solenoidMotor{_botMotorShield.getMotor(4)},
    _griddle{PancakePrinter::GRIDDLE_PIN},
    _gantry{_xStepper, _yStepper},
    _extruder{_pumpMotor, _solenoidMotor} {
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

void PancakePrinter::init() {
    _topMotorShield.begin();
    _botMotorShield.begin();
    _griddle.init();
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
