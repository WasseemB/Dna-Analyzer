//
// Created by parallels on 2/3/20.
//

#ifndef DNASEQUENCE_LIST_H
#define DNASEQUENCE_LIST_H

#include <string>
#include <vector>
#include "Command.h"
#include <map>
#include "../MetaDnaSequence.h"

class List : public Command {
public:
    List();

    void run();

    void print(std::vector<std::pair<size_t, MetaDnaSequence *> > container);

private:
    std::vector<std::string> m_args;

};

#endif //DNASEQUENCE_LIST_H
