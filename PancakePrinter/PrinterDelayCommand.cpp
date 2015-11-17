#include "PrinterDelayCommand.h"

PrinterDelayCommand::PrinterDelayCommand(int ms) : _delay{ms} {}

int PrinterDelayCommand::type() const {
    return PrinterCommandType::DELAY;
}

long PrinterDelayCommand::getDelay() const {
    return _delay;
}
