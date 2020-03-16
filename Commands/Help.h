//
// Created by Wasseem Bazbaz on 16/03/2020.
//

#ifndef DNASEQUENCE_HELP_H
#define DNASEQUENCE_HELP_H

#include "Command.h"


class Help : public Command {
public:
    Help() {};

    void run(std::vector<std::string> args);


    int parse(std::vector<std::string> args);

    std::string getHelp();
    std::string getInfo();

private:
    static const std::string s_HELP;
    static const std::string s_INFO;
};

#endif //DNASEQUENCE_HELP_H
