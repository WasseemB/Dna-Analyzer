//
// Created by parallels on 2/2/20.
//

#include <string>
#include <iostream>
#include "ErrorCommand.h"

const std::string ErrorCommand::s_HELP = "Error Command";
const std::string ErrorCommand::s_INFO = "Error Command";

void ErrorCommand::run(std::vector<std::string> args) {
    std::cout << "Wrong command " << std::endl;
}

std::string ErrorCommand::getHelp() {
    return ErrorCommand::s_HELP;
}

std::string ErrorCommand::getInfo() {
    return ErrorCommand::s_INFO;
}
