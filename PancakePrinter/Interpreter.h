#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <Arduino.h>

#include "PrinterCommand.h"
#include "PrinterMoveCommand.h"
#include "PrinterTempCommand.h"
#include "PrinterExtrudeCommand.h"
#include "PrinterDelayCommand.h"

class Interpreter {
    public:
        PrinterCommand *interpret(String commandStr);

        static String TEMP_STR;
        static String EXTRUDE_STR;
        static String MOVE_STR;
        static String DELAY_STR;

    private:
        PrinterTempCommand *parseTempCommand(String commandStr);
        PrinterExtrudeCommand *parseExtrudeCommand(String commandStr);
        PrinterMoveCommand *parseMoveCommand(String commandStr);
        PrinterDelayCommand *parseDelayCommand(String commandStr);
        void detailedPrint(String str) const;
};

#endif
