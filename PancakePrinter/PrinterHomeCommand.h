#ifndef PRINTER_HOME_COMMAND_H
#define PRINTER_HOME_COMMAND_H

#include "PrinterCommand.h"

class PrinterHomeCommand : public PrinterCommand {
    public:
        virtual int type() const;
};

#endif
