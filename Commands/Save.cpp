//
// Created by parallels on 2/2/20.
//

#include "Save.h"
#include <iostream>
#include "Load.h"
#include "../DnaSequence.h"
#include "../MetaDnaSequence.h"

Save::Save(std::vector<std::string> args) {
    DnaSequence dnaSequence(args[1]);
    if (args.size() == 2) {
        MetaDnaSequence metaDnaSequence(&dnaSequence);
    } else {
        MetaDnaSequence metaDnaSequence(&dnaSequence, args[2]);
    }
}

void Save::run() {
    std::cout << "The save command just ran !" << std::endl;
}