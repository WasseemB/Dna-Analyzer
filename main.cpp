//
// Created by parallels on 1/31/20.
//

#include <iostream>
#include "CLI.h"
#include "CommandParser.h"
#include "Commands/CommandExecuter.h"
#include "Model/DnaSequence.h"
#include <vector>

void print(std::vector<std::string> input) {
    for (size_t i = 0; i < input.size(); i++) {
        std::cout << input[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    CLI cli;
    CommandParser parser;
    std::string data;
    std::vector<std::string> commands;

    while (data != "q") {
        data = cli.input();
        commands = parser.parse(data);
        print(commands);
        Command *command = CommandExecuterFactory::executeCommand(commands[0]);
        command->run(commands);
    }
    std::cout << "Goodbye.\n";
    return 0;

}