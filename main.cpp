#include <iostream>
#include "DnaSequence.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    DnaSequence dnaSequence("AGT");
    cout << dnaSequence << endl;
    cout << dnaSequence.generatePair() << endl;

    //cout << dnaSequence.getSequenceLength() << endl;
    //cout << dnaSequence[2] << endl;


    return 0;
}
