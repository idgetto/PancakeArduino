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
        ~PancakePrinter();
        void listen();
        void finish();
        void calibrate();
        void run(String commandStr);
        void moveTo(float x, float y);
        void setTemperature(float temp);
        void extrudeOn();
        void extrudeOff();
        void init();
        void release();

    private:
        void listenForRecipe();
        void runMoveCommand(PrinterMoveCommand *command);
        void runTempCommand(PrinterTempCommand *command);
        void runExtrudeCommand(PrinterExtrudeCommand *command);
        void runDelayCommand(PrinterDelayCommand *command);

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

        static constexpr int BOT_MOTOR_SHIELD_ADDR = 0x60;
        static constexpr int TOP_MOTOR_SHIELD_ADDR = 0x61;
        static constexpr int X_STEPPER_PORT = 1;
        static constexpr int Y_STEPPER_PORT = 2;

        static constexpr int GRIDDLE_PIN = 9;

        static constexpr int PUMP_MOTOR_SHIELD_ADDR = 0x60;
        static constexpr int PUMP_MOTOR_PORT = 3;
        static constexpr int SOLENOID_MOTOR_SHIELD_ADDR = 0x60;
        static constexpr int SOLENOID_MOTOR_PORT = 4;

        static const String DONE_COMMAND;
        static const String BEGIN_RECIPE;
        static const String READY;
};

#endif
