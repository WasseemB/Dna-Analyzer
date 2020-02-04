//
// Created by parallels on 2/2/20.
//

#include <iostream>
#include "New.h"
#include "../Model/DnaSequence.h"
#include "../DnaContainer.h"
#include "../Model/RealDnaSequence.h"

New::New(std::vector<std::string> args) {
    try {
        RealDnaSequence *metaDnaSequence;
        switch (args.size()) {
            case 2 :
                metaDnaSequence = new RealDnaSequence(new DnaSequence(args[1]));
                DnaContainer::addDna(metaDnaSequence->getId(), metaDnaSequence);
                break;
            case 3:
                metaDnaSequence = new RealDnaSequence(new DnaSequence(args[1]), args[2]);
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
