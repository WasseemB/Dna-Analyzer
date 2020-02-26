//
// Created by parallels on 2/3/20.
//

#include <iostream>
#include "List.h"
#include "../DnaContainer.h"

void print(std::map<size_t, RealDnaSequence *> container) {
    for (std::map<size_t, RealDnaSequence *>::const_iterator it = container.begin();
         it != container.end(); ++it) {
        std::cout << *(it->second) << std::endl;
    }
}

void List::run(std::vector<std::string> args) {
    print(DnaContainer::getContainer());
}


