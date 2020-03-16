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

    int parse(std::vector<std::string> args);

    std::string getHelp();
    std::string getInfo();

private:
    static const std::string s_HELP;
    static const std::string s_INFO;

};

#endif //DNASEQUENCE_NEW_H
