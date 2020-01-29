//
// Created by parallels on 1/18/20.
//

#include <cstring>
#include <iostream>
#include <sstream>
#include "DnaSequence.h"
#include<bits/stdc++.h>


DnaSequence::DnaSequence(const char *sequence) {
    if (!isValid(sequence)) {
        std::cout << "char * sequence constructor";
        throw std::invalid_argument("Nucleotide type is A, C, G or T");
    }
    size_t sequence_len = strlen(sequence);
    this->m_sequence = new char[sequence_len];
    strcpy(this->m_sequence, sequence);
}

DnaSequence::DnaSequence(const std::string &sequence) {
    if (!isValid(sequence.c_str())) {
        std::cout << "std::string sequence constructor";
        throw std::invalid_argument("Nucleotide type is A, C, G or T");
    }
    size_t sequence_len = sequence.length();
    this->m_sequence = new char[sequence_len + 1];
    strcpy(this->m_sequence, sequence.c_str());
}

DnaSequence::~DnaSequence() {
    delete[]this->m_sequence;

}

bool DnaSequence::isValid(const char *sequence) {
    size_t i = 0;

    for (; i < strlen(sequence); ++i) {
        char c = sequence[i];
        if (c == 'A' || c == 'C' || c == 'G' || c == 'T') {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

DnaSequence::DnaSequence(const DnaSequence &dnaSequence) {
    if (!isValid(dnaSequence.m_sequence)) {
        std::cout << "copy operator dna";
        throw std::invalid_argument("Nucleotide type is A, C, G or T");
    }
    delete[]this->m_sequence;
    size_t sequence_len = strlen(dnaSequence.getSequence());
    this->m_sequence = new char[sequence_len];
    strcpy(this->m_sequence, dnaSequence.getSequence());
}

DnaSequence &DnaSequence::operator=(const DnaSequence &dnaSequence) {
    if (!isValid(dnaSequence.m_sequence)) {
        std::cout << "Assignment operator";
        throw std::invalid_argument("Nucleotide type is A, C, G or T");
    }
    if (&dnaSequence == this) {
        return *this;
    }
    delete[]this->m_sequence;
    size_t sequence_len = strlen(dnaSequence.getSequence());
    this->m_sequence = new char[sequence_len];
    strcpy(this->m_sequence, m_sequence);
    return *this;
}

DnaSequence &DnaSequence::operator=(const char *sequence) {
    if (!isValid(sequence)) {
        std::cout << "copy operator char";
        throw std::invalid_argument("Nucleotide type is A, C, G or T");
    }
    delete[]this->m_sequence;
    size_t sequence_len = strlen(sequence);
    this->m_sequence = new char[sequence_len];
    strcpy(this->m_sequence, sequence);
    return *this;
}

DnaSequence &DnaSequence::operator=(const std::string &sequence) {
    if (!isValid(sequence.c_str())) {
        std::cout << "copy operator string";
        throw std::invalid_argument("Nucleotide type is A, C, G or T");
    }
    delete[]this->m_sequence;
    size_t sequence_len = sequence.length();
    this->m_sequence = new char[sequence_len + 1];
    strcpy(this->m_sequence, sequence.c_str());
    return *this;
}

size_t DnaSequence::getSequenceLength() const {
    return strlen(this->m_sequence);
}

bool DnaSequence::operator==(const DnaSequence &rhs) const {
    return strcmp(this->m_sequence, rhs.m_sequence) == 0;
}

bool DnaSequence::operator!=(const DnaSequence &rhs) const {
    return !(rhs == *this);
}

char &DnaSequence::operator[](size_t index) {
    if (index < this->getSequenceLength())
        return this->m_sequence[index];
    throw std::out_of_range("Index is out of bounds!");

}

const char &DnaSequence::operator[](size_t index) const {
    if (index < this->getSequenceLength())
        return this->m_sequence[index];
    throw std::out_of_range("Index is out of bounds!");
}

std::ostream &operator<<(std::ostream &os, const DnaSequence &sequence) {
    os << "Dna Sequence: " << sequence.m_sequence;
    return os;
}

DnaSequence DnaSequence::generatePair() {
    char *pair = new char[this->getSequenceLength()];
    size_t i = 0;
    for (; i < this->getSequenceLength(); ++i) {
        pair[i] = getOpposite(this->m_sequence[i]);
    }
    std::string str_pair = pair;
    delete[]pair;
    return DnaSequence(str_pair);
}

char DnaSequence::getOpposite(char nucl) {
    char pair = 'A';
    if (nucl == 'A')
        pair = 'T';
    else if (nucl == 'T')
        pair = 'A';
    else if (nucl == 'C')
        pair = 'G';
    else if (nucl == 'G')
        pair = 'C';
    return pair;

}

std::string DnaSequence::getSlicedSequence(size_t start, size_t end) const {
    std::string slicedString = this->m_sequence;
    slicedString = slicedString.substr(start, end - 1);
    return slicedString;
}

DnaSequence DnaSequence::reversePair() {
    std::stringstream ss;
    std::string reveresedString(this->generatePair().getSequence());
    size_t len = reveresedString.length();
    size_t n = len - 1;
    size_t i = 0;
    for (; i < (len / 2); i++) {
        //Using the swap method to switch values at each index
        char temp = reveresedString[i];
        reveresedString[i] = reveresedString[n];
        reveresedString[n] = temp;
        n = n - 1;

    }
    return DnaSequence(reveresedString);
}

size_t DnaSequence::findSubSequence(const std::string &sub) const {
    size_t i = 0;
    size_t subLength = sub.length();
    std::cout << subLength << std::endl;
    size_t seqLength = this->getSequenceLength();
    for (; i < seqLength; i++) {
        if (sub == this->getSlicedSequence(i, subLength + 1)) {
            return i;
        }
    }
    return -1;
}

