//
// Created by parallels on 2/2/20.
//

#include <string>
#include <iostream>
#include "ErrorCommand.h"

ErrorCommand::ErrorCommand(std::vector <std::string> args) {

}

void ErrorCommand::run() {
    std::cout << "Wrong command " << std::endl;
}