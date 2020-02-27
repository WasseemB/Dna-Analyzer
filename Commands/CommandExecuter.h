//
// Created by parallels on 2/2/20.
//

#ifndef DNASEQUENCE_COMMANDEXECUTER_H
#define DNASEQUENCE_COMMANDEXECUTER_H

#include <map>
#include "Command.h"


class CommandExecuterFactory {
public:
    static Command *executeCommand(const std::string &command);

    static std::map<std::string, Command *> initCommandMap;
};


#endif //DNASEQUENCE_COMMANDEXECUTER_H
