//
// Created by parallels on 2/3/20.
//

#include <iostream>
#include "List.h"
#include "../DnaContainer.h"

List::List() {
}

void List::run() {
    print(DnaContainer::getContainer());
}

void List::print(std::map<size_t, RealDnaSequence *> container) {
    for (std::map<size_t, RealDnaSequence *>::const_iterator it = container.begin();
         it != container.end(); ++it) {
        std::cout << *(it->second) << std::endl;
    }
}

