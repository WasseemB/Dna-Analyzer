//
// Created by parallels on 2/2/20.
//

#include "Save.h"
#include <iostream>
#include "Load.h"
#include "../DnaSequence.h"
#include "../MetaDnaSequence.h"
#include "../DnaContainer.h"
#include "../File.h"

Save::Save(std::vector<std::string> args) {
    File file;
    std::string data = args[1];
    DnaSequence dnaSequence(data);
//    if (args.size() == 2) {
//        MetaDnaSequence metaDnaSequence(&dnaSequence);
//        DnaContainer::addDna(metaDnaSequence.getId(), &metaDnaSequence);
//    } else {
//        MetaDnaSequence metaDnaSequence(&dnaSequence, args[2]);
//        DnaContainer::addDna(metaDnaSequence.getId(), &metaDnaSequence);
//    }
    file.writeFile(args[2].c_str(), data.c_str());
}

void Save::run() {
    std::cout << "The save command just ran !" << std::endl;
}