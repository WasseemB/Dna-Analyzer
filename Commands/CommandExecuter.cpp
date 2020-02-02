//
// Created by parallels on 2/2/20.
//

#include <iostream>
#include "CommandExecuter.h"
#include "New.h"
#include "Load.h"
#include "Save.h"
#include "ErrorCommand.h"

Command *CommandExecuterFactory::executeCommand(std::vector<std::string> args) {
    if (args.size() < 4) {
        if (args[0] == "new")
            return new New(args);
        else if (args[0] == "load")
            return new Load(args);
        else if (args[0] == "save")
            return new Save(args);
    }
    return new ErrorCommand(args);

}
