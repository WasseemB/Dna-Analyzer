//
// Created by parallels on 2/2/20.
//

#include <iostream>
#include "Load.h"
#include "../DnaSequence.h"
#include "../MetaDnaSequence.h"

Load::Load(std::vector<std::string> args) {
    DnaSequence dnaSequence(args[1]);
    if (args.size() == 2) {
        MetaDnaSequence metaDnaSequence(&dnaSequence);
    } else {
        MetaDnaSequence metaDnaSequence(&dnaSequence, args[2]);
    }
}

void Load::run() {
    std::cout << "The load command just ran !" << std::endl;
}