//
// Created by Wasseem Bazbaz on 29/02/2020.
//
#include <iostream>
#include "Slice.h"
#include "../DnaContainer.h"
#include "../Model/RealDnaSequence.h"

using namespace std;
const string Slice::s_HELP = "slice <seq> <from_ind> <to_ind> [: [@<new_seq_name>|@@]]";
const string Slice::s_INFO = "slice <seq> <from_ind> <to_ind> [: [@<new_seq_name>|@@]]";

static bool isDigit(const string &line) {
    char *p;
    strtol(line.c_str(), &p, 10);
    return *p == 0;
}

int Slice::parse(std::vector<std::string> args) {
    int res = False;
    switch (args.size()) {
        case 4:
            if (args[1][0] == '#' && isDigit(args[1].substr(1)) && isDigit(args[2]) && isDigit(args[3])) {
                res = True;
            } else {
                cout << s_HELP << endl;
            }
            break;
        case 6:
            if (args[1][0] == '#' && isDigit(args[1].substr(1)) && isDigit(args[2]) && isDigit(args[3]) &&
                (args[4][0] == ':')) {
                res = True;
            }
            break;
        default:
            cout << s_HELP << endl;
    }
    return res;
}

void Slice::run(std::vector<std::string> args) {
    switch (args.size()) {
        case 4:
            size_t seq_number = strtoul(args[1].substr(1).c_str(), NULL, 0);
            size_t startIndex = strtoul(args[2].c_str(), NULL, 0);
            size_t endIndex = strtoul(args[3].c_str(), NULL, 0);
            RealDnaSequence *new_sequence = DnaContainer::findById(seq_number);
            string seq = new_sequence->getDnaSequence()->getSlicedSequence(startIndex, endIndex);
            RealDnaSequence *sequence = new RealDnaSequence(new DnaSequence(seq), new_sequence->getName(),
                                                            new_sequence->getId());


            break;

    }
    cout << "The slice is true" << endl;
}

std::string Slice::getHelp() {
    return Slice::s_HELP;
}

std::string Slice::getInfo() {
    return Slice::s_INFO;
}
