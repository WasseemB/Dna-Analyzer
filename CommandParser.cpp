//
// Created by parallels on 2/2/20.
//

#include <cstring>
#include <iostream>
#include "CommandParser.h"

std::vector<std::string> CommandParser::parse(std::string &input) {
    std::vector<std::string> commands;
    char *inp = const_cast<char *>(input.c_str());
    char *token = strtok(inp, " ");
    /* walk through other tokens */
    while (token != NULL) {
        commands.push_back(token);
        token = strtok(NULL, " ");
    }
    return commands;
}
