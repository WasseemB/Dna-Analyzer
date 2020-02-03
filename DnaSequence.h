//
// Created by parallels on 1/18/20.
//

#ifndef DNASEQUENCE_DNASEQUENCE_H
#define DNASEQUENCE_DNASEQUENCE_H

#include <string>
#include <ostream>
#include <vector>

class DnaSequence {

    friend std::ostream &operator<<(std::ostream &os, const DnaSequence &sequence);

public:
    explicit DnaSequence(const char *sequence);

    explicit DnaSequence(const std::string &sequence);

    virtual ~DnaSequence();

    DnaSequence(const DnaSequence &dnaSequence);

    DnaSequence &operator=(const DnaSequence &dnaSequence);

    DnaSequence &operator=(const char *sequence);

    DnaSequence &operator=(const std::string &sequence);

    bool operator==(const DnaSequence &rhs) const;

    bool operator!=(const DnaSequence &rhs) const;

    char &operator[](size_t index);

    const char &operator[](size_t index) const;

    DnaSequence generatePair();

    DnaSequence reversePair();


    // generate ooposite base::pair.
    static char getOpposite(char nucl);

    inline const char *getSequence() const {
        return m_sequence;
    }

    std::string getSlicedSequence(size_t star, size_t end) const;

    int find(const std::string &sub, int start = 0) const;

    int getSubSequenceCount(const std::string &sub) const;

    size_t getSequenceLength() const;

    std::vector<int> findAll(const std::string &sub) const;

    // check validation of sequence (ACGT)
    bool isValid(const char *sequence);

    std::vector<std::string> findConsensus() const;


private:
    char *m_sequence;
};

#endif //DNASEQUENCE_DNASEQUENCE_H