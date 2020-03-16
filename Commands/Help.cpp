//
// Created by Wasseem Bazbaz on 16/03/2020.
//

#include <iostream>
#include "Help.h"
#include "CommandExecuter.h"

using namespace std;

const std::string Help::s_HELP = "help [<command>]";
const std::string Help::s_INFO = "If <command> is not provided, help lists all the available commands.\n";
//                                 "If a valid command is provided, it shows a short explanation of it.\n"
//                                 "If the value provided is not a valid command, a relevant message is printed.";

void Help::run(std::vector<std::string> args) {
    switch (args.size()) {
        case 1: {
            for (auto it = CommandExecuterFactory::initCommandMap.begin();
                 it != CommandExecuterFactory::initCommandMap.end(); it++) {
                cout << it->first  // string (key)
                     << ": "
                     << (it->second)->getHelp()  // string's value
                     << endl;
            }
            break;
        }
        case 2: {
            Command *cmd = CommandExecuterFactory::initCommandMap[args[1]];
            if (cmd)
                cout << cmd->getInfo() << endl;
            else
                cout << "Command [" << args[1] << "] does not exist!" << endl;
            break;
        }
    }
}

std::string Help::getHelp() {
    return Help::s_HELP;
}

std::string Help::getInfo() {
    return Help::s_INFO;
}

int Help::parse(std::vector<std::string> args) {
    return args.size() <= 2;
}
