//
// Created by parallels on 2/2/20.
//

#include <iostream>
#include "Load.h"
#include "../Model/DnaSequence.h"
#include "../DnaContainer.h"
#include "../File.h"

const std::string Load::s_HELP = "load <file_name>  [@<sequence_name>]";

void Load::run(std::vector<std::string> args) {
    File file;
    std::string data = file.readFile(args[1].c_str());
    std::cout << data << std::endl;
    try {
        RealDnaSequence *metaDnaSequence;
        switch (args.size()) {
            case 2:
                metaDnaSequence = new RealDnaSequence(new DnaSequence(data));
                DnaContainer::addDna(metaDnaSequence->getId(), metaDnaSequence);
                break;
            case 3:
                metaDnaSequence = new RealDnaSequence(new DnaSequence(data), args[2].substr(1));
                DnaContainer::addDna(metaDnaSequence->getId(), metaDnaSequence);
                break;
        }

    }
    catch (std::invalid_argument invalid_argument) {
        std::cout << invalid_argument.what() << ", no data was added" << std::endl;
    }

}

int Load::parse(std::vector<std::string> args) {
    int res = False;
    File file;
    if (file.exists(args[1])) {
        switch (args.size()) {
            case 2:
                res = True;
                break;
            case 3:
                if (args[2][0] == '@') {
                    res = True;
                    break;
                } else {
                    std::cout << s_HELP << std::endl;
                    break;
                }
            default:
                std::cout << s_HELP << std::endl;
        }
    } else {
        std::cout << args[1] << " does not exist" << std::endl;
    }
    return res;

}
