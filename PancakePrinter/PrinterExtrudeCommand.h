#ifndef PRINTER_EXTRUDE_COMMAND_H
#define PRINTER_EXTRUDE_COMMAND_H

#include "PrinterCommand.h"

class PrinterExtrudeCommand : public PrinterCommand {
    public:
        PrinterExtrudeCommand(bool extrude);
        virtual int type() const;
        bool extrude() const;
    private:
        bool _extrude;
};

#endif
