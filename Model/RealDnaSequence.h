//
// Created by parallels on 2/4/20.
//

#ifndef DNASEQUENCE_REALDNASEQUENCE_H
#define DNASEQUENCE_REALDNASEQUENCE_H

#include "IDna.h"
#include "DecoratorDnaSequence.h"
#include "DnaSequence.h"

enum State {
    UP_TO_DATE, MODIFIED, NEW
};

class RealDnaSequence : public DecoratorDnaSequence {

    friend std::ostream &operator<<(std::ostream &os, const RealDnaSequence &sequence);

public:
    RealDnaSequence(IDna *iDna, const std::string &name = "", enum State state = NEW);

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

    RealDnaSequence(IDna *iDna, const std::string &name, size_t id, enum State state = NEW);

    void updateState(enum State state);
    std::string getStatusString();
    enum State getStatus();

private:
    IDna *m_iDna;
    std::string m_name;
    size_t m_id;
    static size_t s_ID;
    enum State m_state;

};

#endif //DNASEQUENCE_REALDNASEQUENCE_H
