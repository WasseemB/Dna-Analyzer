//
// Created by parallels on 2/2/20.
//

#include "Save.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include "../DnaContainer.h"
#include "../File.h"


void Save::run(std::vector<std::string> args) {
    File file;
    size_t value = std::atoi(args[1].c_str());
    RealDnaSequence *metaDnaSequence = (DnaContainer::findById(value));
    //Logic here has an issue.
    file.writeFile(args[2].c_str(), metaDnaSequence->getDnaSequence()->getSequence());
    std::cout << "The save command just ran !" << std::endl;
}