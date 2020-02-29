//
// Created by parallels on 2/2/20.
//

#ifndef DNASEQUENCE_SAVE_H
#define DNASEQUENCE_SAVE_H

#include "Command.h"

class Save : public Command {
public:
    Save() {};

    void run(std::vector<std::string> args);

    int parse(std::vector<std::string> args) { return 1; };

};

#endif //DNASEQUENCE_SAVE_H
