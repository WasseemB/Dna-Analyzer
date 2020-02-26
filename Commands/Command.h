//
// Created by parallels on 2/2/20.
//

#ifndef DNASEQUENCE_COMMAND_H
#define DNASEQUENCE_COMMAND_H

#include <vector>
#include <string>

class Command {
public:
    Command() {};

    virtual void run(std::vector<std::string> args) = 0;
};

#endif //DNASEQUENCE_COMMAND_H
