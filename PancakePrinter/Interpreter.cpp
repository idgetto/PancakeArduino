#include "Interpreter.h"

String Interpreter::TEMP_STR = "T";
String Interpreter::EXTRUDE_STR = "E";
String Interpreter::MOVE_STR = "M";
String Interpreter::DELAY_STR = "W";
String Interpreter::HOME_STR = "H";

PrinterCommand *Interpreter::interpret(String commandStr) {

    if (commandStr.startsWith(TEMP_STR)) {
        return parseTempCommand(commandStr);
    } else if (commandStr.startsWith(EXTRUDE_STR)) {
        return parseExtrudeCommand(commandStr);
    } else if (commandStr.startsWith(MOVE_STR)) {
        return parseMoveCommand(commandStr);
    } else if (commandStr.startsWith(DELAY_STR)) {
        return parseDelayCommand(commandStr);
    } else if (commandStr.startsWith(HOME_STR)) {
        return parseHomeCommand(commandStr);
    } else {
        Serial.println("Could not interpret command: ");
        Serial.println(commandStr);
        detailedPrint(commandStr);
        return NULL;
    }
}

void Interpreter::detailedPrint(String str) const {
    String buffer = "";
    for (int i = 0; i < str.length(); ++i) {
        buffer.concat(i);
        buffer.concat(": ");
        buffer.concat(str.charAt(i));
        buffer.concat('\n');
    }
    Serial.print(buffer);
}

PrinterTempCommand *Interpreter::parseTempCommand(String commandStr) {
    int spaceIndex = commandStr.indexOf(" ");
    String tempStr = commandStr.substring(spaceIndex+1);

    float temp = tempStr.toFloat();
    return new PrinterTempCommand(temp);
}

PrinterExtrudeCommand *Interpreter::parseExtrudeCommand(String commandStr) {
    int spaceIndex = commandStr.indexOf(" ");
    String extrudeStr = commandStr.substring(spaceIndex+1);
    int extrudeInt = extrudeStr.toInt();

    bool extrude = extrudeInt == 1;
    return new PrinterExtrudeCommand(extrude);
}

PrinterMoveCommand *Interpreter::parseMoveCommand(String commandStr) {
    int firstSpaceIndex = commandStr.indexOf(" ");
    int secondSpaceIndex = commandStr.indexOf(" ", firstSpaceIndex+1);

    String xStr = commandStr.substring(firstSpaceIndex+1, secondSpaceIndex);
    String yStr = commandStr.substring(secondSpaceIndex+1);


    float x = xStr.toFloat();
    float y = yStr.toFloat();
    return new PrinterMoveCommand(x, y);
}

PrinterDelayCommand *Interpreter::parseDelayCommand(String commandStr) {
    int spaceIndex = commandStr.indexOf(" ");
    String delayStr = commandStr.substring(spaceIndex+1);

    int delay = delayStr.toInt();
    return new PrinterDelayCommand(delay);
}

PrinterHomeCommand *Interpreter::parseHomeCommand(String commandStr) {
    return new PrinterHomeCommand();
}
