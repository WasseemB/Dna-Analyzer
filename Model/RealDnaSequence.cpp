//
// Created by parallels on 2/4/20.
//

#include <iostream>
#include <sstream>
#include "RealDnaSequence.h"
#include "DnaSequence.h"

size_t RealDnaSequence::s_ID = 1;

RealDnaSequence::RealDnaSequence(IDna *iDna, const std::string& name) : DecoratorDnaSequence(iDna) {
    m_iDna = iDna;

    if (name.empty()) {
        std::stringstream ss;
        ss << s_ID;
        m_name = "seq" + ss.str();
    } else {
        m_name = name;
    }
    m_id = s_ID;
    s_ID++;
}

void RealDnaSequence::execute() {
    DecoratorDnaSequence::execute();
    std::cout << "   RealDnaContainer" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const RealDnaSequence &sequence) {
    return os << "[" << sequence.m_id << "] " << sequence.m_name << ": "
              << ((DnaSequence *) (sequence.m_iDna))->getSequence();
}




