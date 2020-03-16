//
// Created by Wasseem Bazbaz on 29/02/2020.
//

#ifndef DNASEQUENCE_SLICE_H
#define DNASEQUENCE_SLICE_H

#include "Command.h"

class Slice : public Command {
public:
    Slice() {};

    void run(std::vector<std::string> args);

    int parse(std::vector<std::string> args);

    std::string getHelp();

    std::string getInfo();

private:
    static const std::string s_HELP;
    static const std::string s_INFO;

};

#endif //DNASEQUENCE_SLICE_H
