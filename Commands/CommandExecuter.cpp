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

Command *CommandExecuterFactory::executeCommand(const std::string &command) {
    if (command == "new")
        return new New();
    else if (command == "load")
        return new Load();
    else if (command == "save")
        return new Save();
    else if (command == "list")
        return new List();
    return new ErrorCommand();

}
