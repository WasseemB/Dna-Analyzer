# DNA Sequence

Dna Sequence implementation in C++.


## DnaSequence.h

```cpp
// create a new sequence from char array or string sequence.
explicit DnaSequence(const char *sequence);
explicit DnaSequence(const std::string &sequence);
// validates if the char sequence is correct.
bool DnaSequence::isValid(const char *sequence);
// returns the length of the sequence.
size_t DnaSequence::getSequenceLength() const;
// generate opposite pair as DNA sequence object.
DnaSequence DnaSequence::generatePair();
// get the opposite of a char.
char DnaSequence::getOpposite(char nucl);
```

