//
// Created by Wasseem Bazbaz on 29/02/2020.
//

#include "Dup.h"
#include <iostream>
#include "../Model/DnaSequence.h"
#include "../DnaContainer.h"
#include "../Model/RealDnaSequence.h"

using namespace std;
const string Dup::s_HELP = "dup <#seq> [@<new_seq_name>]";

bool isDigit(const string &line) {
    char *p;
    strtol(line.c_str(), &p, 10);
    return *p == 0;
}

void Dup::run(vector<string> args) {
    try {
        RealDnaSequence *metaDnaSequence = NULL;
        const string &seq = args[1].substr(1);
        const string &real_seq_name = args[2].substr(1);
        size_t seq_id = strtoul(seq.c_str(), NULL, 0);
        RealDnaSequence *new_sequence = DnaContainer::findById(seq_id);
        switch (args.size()) {
            case 2 : {
                string seq_name = new_sequence->getName();
                seq_name.append("_");
                size_t count = 1;
                string new_seq_name = seq_name + (to_string(count));
                RealDnaSequence *res = DnaContainer::findByString(new_seq_name);
                while (res != NULL) {
                    count++;
                    new_seq_name = seq_name + (to_string(count));
                    res = DnaContainer::findByString(new_seq_name);
                }
                metaDnaSequence = new RealDnaSequence(new DnaSequence(new_sequence->getDnaSequence()->getSequence()),
                                                      new_seq_name);
                break;
            }
            case 3:
                metaDnaSequence = new RealDnaSequence(new DnaSequence(new_sequence->getDnaSequence()->getSequence()),
                                                      real_seq_name);
                break;
        }
        DnaContainer::addDna(metaDnaSequence->getId(), metaDnaSequence);
        DnaContainer::addDna(metaDnaSequence->getName(), metaDnaSequence);

    }
    catch (invalid_argument invalid_argument) {
        cout << invalid_argument.what() << ", no data was added" << endl;
    }
}

int Dup::parse(vector<string> args) {

    int res = False;
    switch (args.size()) {
        case 2 :
            if (args[1][0] == '#') {
                const string &seq = args[1].substr(1);
                if (isDigit(seq)) {
                    res = True;
                    break;
                } else {
                    cout << "after # is not a digit" << endl;
                    break;

                }
            } else {
                cout << s_HELP << endl;
                break;
            }
        case 3:
            if (args[2][0] == '@') {
                res = True;
                break;
            } else {
                cout << s_HELP << endl;
                break;
            }
        default:
            cout << s_HELP << endl;
    }
    return res;

}
