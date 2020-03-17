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
#include "Slice.h"
#include "Help.h"
#include "Show.h"
#include "Quit.h"


static std::map<std::string, Command *> initMap() {
    CLI cli;
    std::map<std::string, Command *> commandMap;
    commandMap["new"] = new New();
    commandMap["load"] = new Load();
    commandMap["save"] = new Save();
    commandMap["list"] = new List();
    commandMap["dup"] = new Dup();
    commandMap["slice"] = new Slice();
    commandMap["help"] = new Help();
    commandMap["show"] = new Show(&cli);
    commandMap["quit"] = new Quit();
    return commandMap;
}

std::map<std::string, Command *> CommandExecuterFactory::initCommandMap = initMap();


Command *CommandExecuterFactory::createCommand(const std::string &command) {
    if (initCommandMap.count(command) == 1) {
        Command *cmd = initCommandMap[command];
        if (cmd)
            return cmd;
    } else {
        std::cout << "Command does not exist " << std::endl;
        return NULL;
    }
}




