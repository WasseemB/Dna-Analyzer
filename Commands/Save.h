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

    std::string getHelp();
    std::string getInfo();

private:
    static const std::string s_HELP;
    static const std::string s_INFO;

};

#endif //DNASEQUENCE_SAVE_H
