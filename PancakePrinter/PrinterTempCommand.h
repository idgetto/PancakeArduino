#ifndef PRINTER_TEMP_COMMAND_H
#define PRINTER_TEMP_COMMAND_H

#include "PrinterCommand.h"

class PrinterTempCommand : public PrinterCommand {
    public:
        PrinterTempCommand(float temp);
        virtual int type() const;
        float getTemperature() const;
    private:
        float _temp;
};

#endif
