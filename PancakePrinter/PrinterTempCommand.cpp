#include "PrinterTempCommand.h"

PrinterTempCommand::PrinterTempCommand(float temp) : _temp{temp} {}

int PrinterTempCommand::type() const {
    return PrinterCommandType::TEMP;
}

float PrinterTempCommand::getTemperature() const {
    return _temp;
}
