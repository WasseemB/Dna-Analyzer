//
// Created by parallels on 2/2/20.
//

#include <iostream>
#include "DnaContainer.h"

std::vector<std::pair<size_t, MetaDnaSequence *> > DnaContainer::s_container;

void DnaContainer::addDna(size_t id, MetaDnaSequence *metaDnaSequence) {
    std::pair<size_t, MetaDnaSequence *> newPair;
    newPair.first = id;
    newPair.second = metaDnaSequence;
    s_container.push_back(newPair);
    std::cout << "[" << id << "]" << " " << metaDnaSequence->getName() << ": " << metaDnaSequence->getSequence()
              << std::endl;
}
