//
// Created by parallels on 2/2/20.
//

#include "MetaDnaSequence.h"
#include <string>
#include <sstream>
#include <iostream>

size_t MetaDnaSequence::s_ID = 1;

MetaDnaSequence::MetaDnaSequence(DnaSequence *dnaSequence)
        : DnaSequence(*dnaSequence) {
    std::stringstream ss;
    ss << s_ID;
    m_name = "seq" + ss.str();
    m_id = s_ID;
    s_ID++;

}

MetaDnaSequence::MetaDnaSequence(DnaSequence *dnaSequence, const std::string &name)
        : DnaSequence(*dnaSequence) {
    std::stringstream ss;
    ss << s_ID;
    m_name = name;
    m_id = s_ID;
    s_ID++;

}


std::ostream &operator<<(std::ostream &os, const MetaDnaSequence &sequence) {
    os << "[" << sequence.getId() << "] " << sequence.getName() << " " << sequence.getSequence();
    return os;
}

std::string MetaDnaSequence::getName() const {
    return this->m_name;
}

size_t MetaDnaSequence::getId() const {
    return this->m_id;
}

MetaDnaSequence &MetaDnaSequence::operator=(const MetaDnaSequence &t) {

    std::cout << "Assignment operator called " << std::endl;
    *this = t;
    return *this;

}
