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

    DnaSequence dnaSequence("ACT");
//
//    DnaContainer::addDna(metaDnaSequence.getId(), &metaDnaSequence);
//    DnaContainer::addDna(2, &metaDnaSequence);
//
//    size_t i = 0;
//    for (; DnaContainer::getContainer().size(); i++)
//        std::cout << DnaContainer::getContainer()[i].first << " "
//                  << DnaContainer::getContainer()[i].second->getSequence() << std::endl;

    while (true && data != "q") {
        data = cli.input();
        commands = parser.parse(data);
        print(commands);
        Command *command = CommandExecuterFactory::executeCommand(commands);
        command->run();
    }

    std::cout << "Goodbye.\n";
    return 0;

}