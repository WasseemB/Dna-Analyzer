//
// Created by parallels on 1/29/20.
//

#ifndef DNASEQUENCE_NUCLEOTIDE_H
#define DNASEQUENCE_NUCLEOTIDE_H

#include <stdexcept>

class Nucleotide {
public:
    Nucleotide() {};

    Nucleotide(char nucl);


private:
    char m_nucl;
};

static bool isValid(char nucl) {
    return (nucl == 'A' || nucl == 'C' || nucl == 'G' || nucl == 'T');
}

Nucleotide::Nucleotide(char nucl) {
    if (isValid(nucl)) {
        this->m_nucl = nucl;
    }
    throw std::invalid_argument("Only A,C,G,T");
}



#endif //DNASEQUENCE_NUCLEOTIDE_H
