//
// Created by parallels on 2/2/20.
//

#ifndef DNASEQUENCE_COMMANDPARSER_H
#define DNASEQUENCE_COMMANDPARSER_H

#include <string>
#include <vector>

class CommandParser {
public:
    std::vector<std::string> parse(std::string& input);
};
#endif //DNASEQUENCE_COMMANDPARSER_H
