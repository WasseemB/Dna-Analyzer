//
// Created by parallels on 2/2/20.
//

#include <iostream>
#include "New.h"
#include "../DnaSequence.h"
#include "../MetaDnaSequence.h"
#include "../DnaContainer.h"

New::New(std::vector<std::string> args) {
    try {
        DnaSequence dnaSequence(args[1]);
        MetaDnaSequence *metaDnaSequence;
        switch (args.size()) {
            case 2 :
                metaDnaSequence = new MetaDnaSequence(&dnaSequence);
                DnaContainer::addDna(metaDnaSequence->getId(), metaDnaSequence);
                break;
            case 3:
                metaDnaSequence = new MetaDnaSequence(&dnaSequence, args[2]);
                DnaContainer::addDna(metaDnaSequence->getId(), metaDnaSequence);
                break;
            default:
                std::cout << "new <sequence> [@<sequence_name>]" << std::endl;

        }
    }
    catch (std::invalid_argument invalid_argument) {
        std::cout << invalid_argument.what() << ", no data was added" << std::endl;
    }
}

void New::run() {
    std::cout << "The new command just ran !" << std::endl;
}
