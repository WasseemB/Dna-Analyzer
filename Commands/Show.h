//
// Created by Wasseem Bazbaz on 16/03/2020.
//

#ifndef DNASEQUENCE_SHOW_H
#define DNASEQUENCE_SHOW_H

#include "Command.h"

class Show : public Command {
public:
    Show() {};

    void run(std::vector<std::string> args);

    int parse(std::vector<std::string> args);

    std::string getHelp();

    std::string getInfo();

private:
    static const std::string s_HELP;
    static const std::string s_INFO;

};

#endif //DNASEQUENCE_SHOW_H
