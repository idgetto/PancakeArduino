#ifndef PRINTER_MOVE_COMMAND_H
#define PRINTER_MOVE_COMMAND_H

#include "PrinterCommand.h"

class PrinterMoveCommand : public PrinterCommand {
    public:
        PrinterMoveCommand(float x, float y);
        virtual int type() const;
        float getX() const;
        float getY() const;
    private:
        float _x;
        float _y;
};

#endif
