//
// Created by parallels on 2/2/20.
//

#include <iostream>
#include "CommandExecuter.h"
#include "New.h"
#include "Load.h"
#include "Save.h"
#include "ErrorCommand.h"
#include "List.h"
#include "Dup.h"


static std::map<std::string, Command *> initMap() {
    std::map<std::string, Command *> commandMap;
    commandMap["new"] = new New();
    commandMap["load"] = new Load();
    commandMap["save"] = new Save();
    commandMap["list"] = new List();
    commandMap["dup"] = new Dup();
    return commandMap;
}

std::map<std::string, Command *> CommandExecuterFactory::initCommandMap = initMap();

Command *CommandExecuterFactory::executeCommand(const std::string &command) {
    Command *cmd = initCommandMap[command];
    if (cmd)
        return cmd;
    return new ErrorCommand();
}




