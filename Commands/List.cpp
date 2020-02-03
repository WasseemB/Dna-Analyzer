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

void List::print(std::vector<std::pair<size_t, MetaDnaSequence *> > container) {
    size_t i = 0;
    size_t container_length = container.size();
    for (; i < container_length; i++) {
        MetaDnaSequence *metaDnaSequence = container[i].second;
        std::cout << "[" << metaDnaSequence->getId() << "]" << " " << ": "
                  << metaDnaSequence->getName()
                  << std::endl;
    }
}

