#include "Interpreter.h"

String Interpreter::TEMP_STR = "TEMP";
String Interpreter::EXTRUDE_STR = "EXTRUDE";
String Interpreter::MOVE_STR = "MOVE";
String Interpreter::DELAY_STR = "DELAY";

PrinterCommand *Interpreter::interpret(String commandStr) {

    if (commandStr.startsWith(TEMP_STR)) { 
        return parseTempCommand(commandStr);
    } else if (commandStr.startsWith(EXTRUDE_STR)) {
        return parseExtrudeCommand(commandStr);
    } else if (commandStr.startsWith(MOVE_STR)) {
        return parseMoveCommand(commandStr);
    } else if (commandStr.startsWith(DELAY_STR)) {
        return parseDelayCommand(commandStr);
    } else {
        Serial.println("Could not interpret command: ");
        Serial.println(commandStr);
        return NULL;
    }
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
