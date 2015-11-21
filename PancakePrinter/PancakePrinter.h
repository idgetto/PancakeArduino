#ifndef PANCAKE_PRINTER_H
#define PANCAKE_PRINTER_H

#include "Gantry.h"
#include "Griddle.h"
#include "Extruder.h"
#include "Interpreter.h"
#include "CommandQueue.h"
#include "CommandCourier.h"

class PancakePrinter {
    public:
        PancakePrinter();
        void listen();
        void finish();
        void run(String commandStr);
        void moveTo(float x, float y);
        void setTemperature(float temp);
        void extrudeOn();
        void extrudeOff();
        void init();

    private:
        void runMoveCommand(PrinterMoveCommand *command);
        void runTempCommand(PrinterTempCommand *command);
        void runExtrudeCommand(PrinterExtrudeCommand *command);
        void runDelayCommand(PrinterDelayCommand *command);

        void getNextCommand(CommandQueue& q);

        Adafruit_MotorShield _topMotorShield;
        Adafruit_MotorShield _botMotorShield;
        Adafruit_StepperMotor *_xStepper;
        Adafruit_StepperMotor *_yStepper;
        Adafruit_DCMotor *_pumpMotor;
        Adafruit_DCMotor *_solenoidMotor;

        Griddle _griddle;
        Gantry _gantry;
        Extruder _extruder;
        Interpreter _interpreter;

        CommandCourier _commandCourier;
        CommandQueue _commandQueue;

        static const int GANTRY_X_MOTOR_SHIELD_ADDR = 0x60;
        static const int GANTRY_Y_MOTOR_SHIELD_ADDR = 0x61;
        static const int GANTRY_X_STEPPER_PORT = 2;
        static const int GANTRY_Y_STEPPER_PORT = 1;

        static const int GRIDDLE_PIN = 9;

        static const int PUMP_MOTOR_SHIELD_ADDR = 0x60;
        static const int PUMP_MOTOR_PORT = 1;
        static const int SOLENOID_MOTOR_SHIELD_ADDR = 0x60;
        static const int SOLENOID_MOTOR_PORT = 2;

        static const String DONE_COMMAND;
};

#endif
