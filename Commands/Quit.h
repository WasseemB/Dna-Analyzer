//
// Created by Wasseem Bazbaz on 16/03/2020.
//

#ifndef DNASEQUENCE_QUIT_H
#define DNASEQUENCE_QUIT_H

#include "Command.h"

class Quit : public Command {
public:
    Quit() {};

    void run(std::vector<std::string> args);

    int parse(std::vector<std::string> args) { return 1; };

    std::string getHelp();

    std::string getInfo();

private:
    static const std::string s_HELP;
    static const std::string s_INFO;

};

#endif //DNASEQUENCE_QUIT_H
