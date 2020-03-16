//
// Created by parallels on 2/2/20.
//

#include "Save.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include "../DnaContainer.h"
#include "../File.h"

using namespace std;
const string Save::s_HELP = "save <seq> [<filename>]";
const string Save::s_INFO = "saves sequence <seq> to a file.\n"
                            "If <filename> is not provided, the sequence name is being used.\n"
                            "The filename is suffixed by .rawdna.";

void Save::run(std::vector<std::string> args) {
    File file;
    size_t value = std::atoi(args[1].c_str());
    RealDnaSequence *metaDnaSequence = (DnaContainer::findById(value));
    // we are working with pointer
    metaDnaSequence->updateState(UP_TO_DATE);
    //Logic here has an issue.
    file.writeFile(args[2].c_str(), metaDnaSequence->getDnaSequence()->getSequence());
    std::cout << "The save command just ran !" << std::endl;
}

std::string Save::getHelp() {
    return Save::s_HELP;
}

std::string Save::getInfo() {
    return Save::s_INFO;
}
