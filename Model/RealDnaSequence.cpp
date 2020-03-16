//
// Created by parallels on 2/4/20.
//

#include <iostream>
#include <sstream>
#include "RealDnaSequence.h"
#include "DnaSequence.h"

using namespace std;
size_t RealDnaSequence::s_ID = 1;

RealDnaSequence::RealDnaSequence(IDna *iDna, const std::string &name, enum State state) : DecoratorDnaSequence(
        iDna) {
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
    m_state = state;

}

RealDnaSequence::RealDnaSequence(IDna *iDna, const std::string &name, size_t id, enum State state)
        : DecoratorDnaSequence(iDna) {
    m_iDna = iDna;

    if (name.empty()) {
        m_name = "seq" + std::to_string(id);
    } else {
        m_name = name;
    }
    m_id = id;
    m_state = state;
}

void RealDnaSequence::execute() {
    DecoratorDnaSequence::execute();
    std::cout << "   RealDnaContainer" << std::endl;
}


ostream &operator<<(std::ostream &os, const RealDnaSequence &sequence) {
    string stateString;
    switch (sequence.m_state) {
        case NEW  :
            stateString = "o";
            break;
        case UP_TO_DATE:
            stateString = "-";
            break;
        case MODIFIED :
            stateString = "*";
            break;
    }
    return os << stateString << " [" << sequence.m_id << "] " << sequence.m_name << ": "
              << ((DnaSequence *) (sequence.m_iDna))->getSequence();
}

void RealDnaSequence::updateState(enum State state) {
    this->m_state = state;
}

std::string RealDnaSequence::getStatusString() {
    string stateString;
    switch (this->m_state) {
        case NEW  :
            stateString = "new";
            break;
        case UP_TO_DATE:
            stateString = "up to date";
            break;
        case MODIFIED :
            stateString = "modified";
            break;
    }
    return stateString;
}




