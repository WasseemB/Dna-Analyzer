//
// Created by parallels on 2/3/20.
//

#ifndef DNASEQUENCE_LIST_H
#define DNASEQUENCE_LIST_H

#include <string>
#include <vector>
#include "Command.h"
#include <map>
#include "../Model/RealDnaSequence.h"

class List : public Command {
public:
    List() {};

    void run(std::vector<std::string> args);


    int parse(std::vector<std::string> args) { return 1; };

    std::string getHelp();
    std::string getInfo();

private:
    static const std::string s_HELP;
    static const std::string s_INFO;

};

#endif //DNASEQUENCE_LIST_H
