//
// Created by parallels on 2/2/20.
//

#include <iostream>
#include <map>
#include "DnaContainer.h"

std::map<size_t, RealDnaSequence *>  DnaContainer::s_container;
std::map<std::string, RealDnaSequence *>  DnaContainer::s_stringContainer;

void DnaContainer::addDna(size_t id, RealDnaSequence *metaDnaSequence) {
    s_container[id] = metaDnaSequence;
//    std::cout << *metaDnaSequence << std::endl;
}


std::map<size_t, RealDnaSequence *> DnaContainer::getContainer() {
    return s_container;
}

std::map<std::string, RealDnaSequence *> DnaContainer::getStringContainer() {
    return s_stringContainer;
}

RealDnaSequence *DnaContainer::findById(size_t id) {
    return (DnaContainer::getContainer().find(id)->second);
}

RealDnaSequence *DnaContainer::findByString(const std::string &name) {
    std::map<std::string, RealDnaSequence *>::iterator it;
    std::map<std::string, RealDnaSequence *> container = DnaContainer::getStringContainer();
    it = container.find(name);
    if (it == container.end())
        return NULL;
    return (DnaContainer::getStringContainer().find(name)->second);
}

void DnaContainer::addDna(const std::string &string, RealDnaSequence *metaDnaSequence) {
    s_stringContainer[string] = metaDnaSequence;
    std::cout << *metaDnaSequence << std::endl;
}


