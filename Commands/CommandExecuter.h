//
// Created by parallels on 2/2/20.
//

#ifndef DNASEQUENCE_COMMANDEXECUTER_H
#define DNASEQUENCE_COMMANDEXECUTER_H

#include "Command.h"

class CommandExecuterFactory {
public:
    static Command* executeCommand(std::vector<std::string> args);
};
#endif //DNASEQUENCE_COMMANDEXECUTER_H
