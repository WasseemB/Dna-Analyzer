//
// Created by parallels on 2/2/20.
//

#ifndef DNASEQUENCE_NEW_H
#define DNASEQUENCE_NEW_H

#include "Command.h"

class New : public Command {
public:
    New() {};

    void run(std::vector<std::string> args);
};

#endif //DNASEQUENCE_NEW_H
