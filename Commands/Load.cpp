//
// Created by parallels on 2/2/20.
//

#include <iostream>
#include "Load.h"
#include "../DnaSequence.h"
#include "../MetaDnaSequence.h"
#include "../DnaContainer.h"
#include "../File.h"

Load::Load(std::vector<std::string> args) {
    File file;
    std::string data = file.readFile(args[1].c_str());
    DnaSequence dnaSequence(data);
    if (args.size() == 2) {
        MetaDnaSequence metaDnaSequence(&dnaSequence);
        DnaContainer::addDna(metaDnaSequence.getId(), &metaDnaSequence);
    } else {
        MetaDnaSequence metaDnaSequence(&dnaSequence, args[2]);
        DnaContainer::addDna(metaDnaSequence.getId(), &metaDnaSequence);
    }
}

void Load::run() {
    std::cout << "The load command just ran !" << std::endl;
}