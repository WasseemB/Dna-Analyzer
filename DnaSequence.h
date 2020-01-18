//
// Created by parallels on 1/18/20.
//

#ifndef DNASEQUENCE_DNASEQUENCE_H
#define DNASEQUENCE_DNASEQUENCE_H

#include <string>
#include <ostream>

class DnaSequence {

    friend std::ostream &operator<<(std::ostream &os, const DnaSequence &sequence);

public:
    explicit DnaSequence(const char *sequence);

    explicit DnaSequence(const std::string &sequence);

    ~DnaSequence();

    DnaSequence(const DnaSequence &dnaSequence);

    DnaSequence &operator=(const DnaSequence &dnaSequence);

    DnaSequence &operator=(const char *sequence);

    DnaSequence &operator=(const std::string &sequence);

    bool operator==(const DnaSequence &rhs) const;

    bool operator!=(const DnaSequence &rhs) const;

    char &operator[](size_t index);

    const char &operator[](size_t index) const;

    DnaSequence generatePair();

    // generate ooposite base::pair.
    static char getOpposite(char nucl);

    inline char *getSequence() const {
        return m_sequence;
    }

    size_t getSequenceLength() const;
    // check validation of sequence (ACGT)
    bool isValid(const char *sequence);


private:
    char *m_sequence;
};

#endif //DNASEQUENCE_DNASEQUENCE_H
