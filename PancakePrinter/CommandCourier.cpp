#include <Arduino.h>
#include "CommandCourier.h"

// Reads a printer command from the serial buffer.
// Commands should end in a new line character.
String CommandCourier::readCommand() const {
    String command = Serial.readStringUntil(NEW_LINE);
    command.trim();
    return command;
}

void CommandCourier::reportGot(String command) const {
    String msg = CommandCourier::GOT_MSG;
    msg.replace(CommandCourier::COMMAND, command);

    Serial.println(msg);
    Serial.flush();
}

void CommandCourier::reportComplete(String command) const {
    String msg = CommandCourier::COMPLETED_MSG;
    msg.replace(CommandCourier::COMMAND, command);

    Serial.println(msg);
    Serial.flush();
}

const String CommandCourier::COMMAND = "COMMAND";
const String CommandCourier::GOT_MSG = "Got: \"COMMAND\"";
const String CommandCourier::COMPLETED_MSG = "Completed: \"COMMAND\"";
