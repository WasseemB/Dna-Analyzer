//
// Created by Wasseem Bazbaz on 16/03/2020.
//

#ifndef DNASEQUENCE_SHOW_H
#define DNASEQUENCE_SHOW_H

#include "Command.h"
#include "../CLI.h"

class Show : public Command {
public:
    Show(CLI *cli) { m_cli = cli; };

    void run(std::vector<std::string> args);

    int parse(std::vector<std::string> args);

    std::string getHelp();

    std::string getInfo();

private:
    CLI *m_cli;
    static const std::string s_HELP;
    static const std::string s_INFO;

};

#endif //DNASEQUENCE_SHOW_H
