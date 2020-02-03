//
// Created by parallels on 2/2/20.
//

#ifndef DNASEQUENCE_METADNASEQUENCE_H
#define DNASEQUENCE_METADNASEQUENCE_H

#include "DnaSequence.h"

class MetaDnaSequence : public DnaSequence {
    friend std::ostream &operator<<(std::ostream &os, const MetaDnaSequence &sequence);


public:
    MetaDnaSequence &operator=(const MetaDnaSequence &t);

    MetaDnaSequence(DnaSequence *dnaSequence, const std::string &name);

    MetaDnaSequence(DnaSequence *dnaSequence);

    std::string getName() const;

    size_t getId() const;

private:
    std::string m_name;
    size_t m_id;
    static size_t s_ID;
};

#endif //DNASEQUENCE_METADNASEQUENCE_H
