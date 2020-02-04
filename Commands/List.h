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
    List();

    void run();

    void print(std::map<size_t, RealDnaSequence *> container);

private:
    std::vector<std::string> m_args;

};

#endif //DNASEQUENCE_LIST_H
