//
// Created by Wasseem Bazbaz on 29/02/2020.
//

#ifndef DNASEQUENCE_DUP_H
#define DNASEQUENCE_DUP_H

#include "Command.h"

class Dup : public Command {
public:
    Dup() {};

    void run(std::vector<std::string> args);

    int parse(std::vector<std::string> args);

private:
    static const std::string s_HELP;

};

#endif //DNASEQUENCE_DUP_H
