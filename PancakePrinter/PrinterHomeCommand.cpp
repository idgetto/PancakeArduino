#include "PrinterHomeCommand.h"

int PrinterDelayCommand::type() const {
    return PrinterCommandType::HOME;
}
