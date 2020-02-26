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

Command *CommandExecuterFactory::executeCommand(std::vector<std::string> args) {
    if (args[0] == "new")
        return new New(args);
    else if (args[0] == "load")
        return new Load(args);
    else if (args[0] == "save")
        return new Save(args);
    else if (args[0] == "list")
        return new List();
    return new ErrorCommand(args);

}
