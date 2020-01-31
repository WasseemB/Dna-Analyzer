//
// Created by parallels on 1/31/20.
//

#include <iostream>
#include "DnaSequence.h"
#include <vector>

void print(std::vector<std::string> input) {
    for (int i = 0; i < input.size(); i++) {
        std::cout << input[i] << " ";
    }
}

int main() {
    DnaSequence dnaSequence("AATGTAGATAGTAATGA");
    //  std::cout << dnaSequence.getSlicedSequence(0,4) << std::endl;
//    DnaSequence dnaSequence("AGTCGACGTCAAGTC");
//    std::cout << dnaSequence.find("AGT") << std::endl;
//    print(dnaSequence.findAll("AGT"));
    //testing::ElementsAre(1, 7, 12))
    std::vector<std::string> res = dnaSequence.findConsensus();
    print(res);
//    return 0;
}