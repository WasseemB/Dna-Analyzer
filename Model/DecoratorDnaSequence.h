//
// Created by parallels on 2/4/20.
//

#ifndef DNASEQUENCE_DECORATORDNASEQUENCE_H
#define DNASEQUENCE_DECORATORDNASEQUENCE_H

#include "IDna.h"

class DecoratorDnaSequence : public IDna {
    IDna *m_iDna;
public:
    DecoratorDnaSequence(IDna *iDna) {
        m_iDna = iDna;
    }

    virtual void execute();
};

#endif //DNASEQUENCE_DECORATORDNASEQUENCE_H
