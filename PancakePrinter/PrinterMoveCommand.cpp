#include "PrinterMoveCommand.h"


PrinterMoveCommand::PrinterMoveCommand(float x, float y) : _x{x}, _y{y} {}

int PrinterMoveCommand::type() const {
    return PrinterCommandType::MOVE;
}

float PrinterMoveCommand::getX() const {
    return _x;
}

float PrinterMoveCommand::getY() const {
    return _y;
}
