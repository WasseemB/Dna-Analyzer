//
// Created by parallels on 2/2/20.
//

#ifndef DNASEQUENCE_ERRORCOMMAND_H
#define DNASEQUENCE_ERRORCOMMAND_H

#include <vector>
#include "Command.h"

class ErrorCommand : public Command {
public:
    ErrorCommand() {};

    void run(std::vector<std::string> args);

    int parse(std::vector<std::string> args) { return 1; };


};

#endif //DNASEQUENCE_ERRORCOMMAND_H
