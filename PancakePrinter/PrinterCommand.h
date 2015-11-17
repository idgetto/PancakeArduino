#ifndef PRINTER_COMMAND_H
#define PRINTER_COMMAND_H

#include "PrinterCommandType.h"

class PrinterCommand {
    public:
        virtual int type() const = 0;
};

#endif
