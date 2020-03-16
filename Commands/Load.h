//
// Created by parallels on 2/2/20.
//

#ifndef DNASEQUENCE_LOAD_H
#define DNASEQUENCE_LOAD_H

#include <vector>
#include "Command.h"

class Load : public Command {
public:
    Load() {};

    void run(std::vector<std::string> args);

    int parse(std::vector<std::string> args);
    std::string getHelp();

    std::string getInfo();

private:
    static const std::string s_HELP;
    static const std::string s_INFO;

};

#endif //DNASEQUENCE_LOAD_H
