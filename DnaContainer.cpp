//
// Created by parallels on 2/2/20.
//

#include <iostream>
#include <map>
#include "DnaContainer.h"

std::map<size_t, RealDnaSequence *>  DnaContainer::s_container;

void DnaContainer::addDna(size_t id, RealDnaSequence *metaDnaSequence) {
    s_container[id] = metaDnaSequence;
    std::cout << *metaDnaSequence << std::endl;
}


std::map<size_t, RealDnaSequence *> DnaContainer::getContainer() {
    return s_container;
}

RealDnaSequence *DnaContainer::findById(size_t id) {
    return (DnaContainer::getContainer().find(id)->second);
}
