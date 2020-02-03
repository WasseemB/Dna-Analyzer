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
    if (file.exists(args[1].c_str())) {
        std::string data = file.readFile(args[1].c_str());
        std::cout << data << std::endl;
        try {
            DnaSequence dnaSequence(data);
            MetaDnaSequence *metaDnaSequence;
            switch (args.size()) {
                case 2:
                    metaDnaSequence = new MetaDnaSequence(&dnaSequence);
                    DnaContainer::addDna(metaDnaSequence->getId(), metaDnaSequence);
                    break;
                case 3:
                    metaDnaSequence = new MetaDnaSequence(&dnaSequence, args[2]);
                    DnaContainer::addDna(metaDnaSequence->getId(), metaDnaSequence);
                    break;
                default:
                    std::cout << "load <file_name>  [@<sequence_name>]" << std::endl;
            }

        }
        catch (std::invalid_argument invalid_argument) {
            std::cout << invalid_argument.what() << ", no data was added" << std::endl;
        }
    } else {
        std::cout << args[1] << " does not exist" << std::endl;

    }
}

void Load::run() {
    std::cout << "The load command just ran !" << std::endl;
}