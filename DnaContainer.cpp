//
// Created by parallels on 2/2/20.
//

#include <iostream>
#include <map>
#include "DnaContainer.h"

std::vector<std::pair<size_t, MetaDnaSequence *> > DnaContainer::s_container;

void DnaContainer::addDna(size_t id, MetaDnaSequence *metaDnaSequence) {
    // there is a big bad error here. check it out here.
    std::pair<size_t, MetaDnaSequence *> newPair;
    newPair.first = id;
    newPair.second = metaDnaSequence;
    s_container.push_back(newPair);
    std::cout << "[" << id << "]" << " " << newPair.second->getName() << ": " << newPair.second->getSequence()
              << std::endl;
}


std::vector<std::pair<size_t, MetaDnaSequence *> > DnaContainer::getContainer() {
    return s_container;
}

MetaDnaSequence DnaContainer::findById(size_t id) {
    size_t i = 0;
    size_t container_length = DnaContainer::s_container.size();
    for (; i < container_length; i++) {
        if (DnaContainer::s_container[i].first == id) {
            std::cout << DnaContainer::s_container[i].second->getSequence() << std::endl;
            return MetaDnaSequence(DnaContainer::s_container[i].second);
        }
    }
    return NULL;
}
