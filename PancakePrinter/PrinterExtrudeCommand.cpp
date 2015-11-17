#include "PrinterExtrudeCommand.h"

PrinterExtrudeCommand::PrinterExtrudeCommand(bool extrude) : _extrude{extrude} {}

int PrinterExtrudeCommand::type() const {
    return PrinterCommandType::EXTRUDE;
}

bool PrinterExtrudeCommand::extrude() const {
    return _extrude;
}
