//
// Created by parallels on 2/3/20.
//

#include <iostream>
#include "List.h"
#include "../DnaContainer.h"

using namespace std;
const std::string List::s_HELP = "list";
const std::string List::s_INFO = "shows all the sequences in the system, by order.\n";

void print(std::map<size_t, RealDnaSequence *> container) {
    if (container.empty()) {
        cout << "No items inside the container" << endl;
    } else {
        for (std::map<size_t, RealDnaSequence *>::const_iterator it = container.begin();
             it != container.end(); ++it) {
            std::cout << *(it->second) << std::endl;
        }
    }
}

void print(std::map<string, RealDnaSequence *> container) {
    for (std::map<string, RealDnaSequence *>::const_iterator it = container.begin();
         it != container.end(); ++it) {
        std::cout << *(it->second) << std::endl;
    }
}

void List::run(std::vector<std::string> args) {
    print(DnaContainer::getContainer());
}

std::string List::getHelp() {
    return List::s_HELP;
}

std::string List::getInfo() {
    return List::s_INFO;
}


