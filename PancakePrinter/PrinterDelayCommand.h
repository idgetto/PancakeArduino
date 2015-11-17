#ifndef PRINTER_DELAY_COMMAND_H
#define PRINTER_DELAY_COMMAND_H

#include "PrinterCommand.h"

class PrinterDelayCommand : public PrinterCommand {
    public:
        PrinterDelayCommand(int ms);
        virtual int type() const;
        long getDelay() const;
    private:
        int _delay;
};

#endif
