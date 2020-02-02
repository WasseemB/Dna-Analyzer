//
// Created by parallels on 2/2/20.
//

#include <iostream>
#include "New.h"
#include "../DnaSequence.h"
#include "../MetaDnaSequence.h"
#include "../DnaContainer.h"

New::New(std::vector<std::string> args) {
    DnaSequence dnaSequence(args[1]);
    if (args.size() == 2) {
        MetaDnaSequence metaDnaSequence(&dnaSequence);
        DnaContainer::addDna(metaDnaSequence.getId(), &metaDnaSequence);
    } else {
        MetaDnaSequence metaDnaSequence(&dnaSequence, args[2]);
        DnaContainer::addDna(metaDnaSequence.getId(), &metaDnaSequence);
    }
}

void New::run() {
    std::cout << "The new command just ran !" << std::endl;
}
