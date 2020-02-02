//
// Created by parallels on 2/2/20.
//

#include <iostream>
#include "CLI.h"

std::string CLI::input() {
    for (std::string line; std::cout << "> cmd >>> " && std::getline(std::cin, line);) {
        if (!line.empty()) { return line; }
    }
    return "";
}
