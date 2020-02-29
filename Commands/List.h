//
// Created by parallels on 2/3/20.
//

#ifndef DNASEQUENCE_LIST_H
#define DNASEQUENCE_LIST_H

#include <string>
#include <vector>
#include "Command.h"
#include <map>
#include "../Model/RealDnaSequence.h"

class List : public Command {
public:
    List() {};

    void run(std::vector<std::string> args);


    int parse(std::vector<std::string> args) { return 1; };

};

#endif //DNASEQUENCE_LIST_H
