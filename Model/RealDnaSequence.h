//
// Created by parallels on 2/4/20.
//

#ifndef DNASEQUENCE_REALDNASEQUENCE_H
#define DNASEQUENCE_REALDNASEQUENCE_H

#include "IDna.h"
#include "DecoratorDnaSequence.h"
#include "DnaSequence.h"

class RealDnaSequence : public DecoratorDnaSequence {
    friend std::ostream &operator<<(std::ostream &os, const RealDnaSequence &sequence);

public:
    RealDnaSequence(IDna *iDna, std::string name = "");

    virtual void execute();

    inline size_t getId() const {
        return m_id;
    }

    inline std::string getName() const {
        return m_name;
    }

    inline DnaSequence *getDnaSequence() {
        return ((DnaSequence *) (m_iDna));
    }

private:
    IDna *m_iDna;
    std::string m_name;
    size_t m_id;
    static size_t s_ID;

};

#endif //DNASEQUENCE_REALDNASEQUENCE_H
