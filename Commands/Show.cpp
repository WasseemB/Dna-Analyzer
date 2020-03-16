//
// Created by Wasseem Bazbaz on 16/03/2020.
//
#include <iostream>
#include "Show.h"
#include "../Model/RealDnaSequence.h"
#include "../DnaContainer.h"

using namespace std;
const string Show::s_HELP = "show `<seq>` [<num_chars>]";
const string Show::s_INFO = "Shows the sequence: Its ID, its name, its status and the sequence itself.";

static bool isDigit(const string &line) {
    char *p;
    strtol(line.c_str(), &p, 10);
    return *p == 0;
}

std::string Show::getHelp() {
    return Show::s_HELP;
}

std::string Show::getInfo() {
    return Show::s_INFO;
}

void Show::run(std::vector<std::string> args) {
    try {
        RealDnaSequence *metaDnaSequence = NULL;
        const string &seq = args[1].substr(1);
        string seq_name;
        size_t seq_id = strtoul(seq.c_str(), NULL, 0);
        RealDnaSequence *new_sequence = DnaContainer::findById(seq_id);
        if (new_sequence == NULL) {
            cout << "Sequence does not exist " << endl;
            return;
        }
        string sequenceData(new_sequence->getDnaSequence()->getSequence());
        switch (args.size()) {
            case 2 :
                cout << "[" << new_sequence->getId() << "] " << new_sequence->getName() << " "
                     << new_sequence->getStatusString() << endl;
                cout << sequenceData.substr(0, 99) << endl;
                break;
            case 3:
                size_t seqLength = strtoul(args[2].c_str(), NULL, 0);
                cout << "[" << new_sequence->getId() << "] " << new_sequence->getName() << " "
                     << new_sequence->getStatusString() << endl;
                cout << sequenceData.substr(0, seqLength) << endl;
                break;
        }
    }
    catch (exception &e) {
        cout << "Here we go again " << e.what() << endl;
    }

}

int Show::parse(std::vector<std::string> args) {
    int res = False;
    switch (args.size()) {
        case 2 :
            if (args[1][0] == '#') {
                const string &seq = args[1].substr(1);
                if (isDigit(seq)) {
                    res = True;
                } else {
                    cout << "after # is not a digit" << endl;
                }
            } else {
                cout << s_HELP << endl;
            }
            break;
        case 3:
            if (args[1][0] == '#') {
                const string &seq = args[1].substr(1);
                if (isDigit(seq)) {
                    const string &amount = args[2];
                    if (isDigit(amount)) {
                        res = True;
                        cout << amount << endl;
                    }
                } else {
                    cout << "after # is not a digit" << endl;
                }
            } else {
                cout << s_HELP << endl;
            }
            break;
        default:
            cout << s_HELP << endl;
    }
    return res;
}
