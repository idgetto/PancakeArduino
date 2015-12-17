#include "PrinterHomeCommand.h"

int PrinterHomeCommand::type() const {
    return PrinterCommandType::HOME;
}
