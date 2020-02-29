//
// Created by parallels on 2/2/20.
//

#include <iostream>
#include "New.h"
#include "../Model/DnaSequence.h"
#include "../DnaContainer.h"
#include "../Model/RealDnaSequence.h"

using namespace std;
const string New::s_HELP = "new <sequence> [@<sequence_name>]";

void New::run(vector<string> args) {
    try {
        RealDnaSequence *metaDnaSequence = NULL;
        const string &sequence = args[1];
        switch (args.size()) {
            case 2 :
                metaDnaSequence = new RealDnaSequence(new DnaSequence(args[1]));
                break;
            case 3:
                const string &sequence_name = args[2].substr(1);
                metaDnaSequence = new RealDnaSequence(new DnaSequence(args[1]), sequence_name);
                break;
        }
        DnaContainer::addDna(metaDnaSequence->getId(), metaDnaSequence);
        DnaContainer::addDna(metaDnaSequence->getName(), metaDnaSequence);
    }
    catch (invalid_argument invalid_argument) {
        cout << invalid_argument.what() << ", no data was added" << endl;
    }
}

int New::parse(vector<string> args) {

    int res = False;
    switch (args.size()) {
        case 2 :
            res = True;
            break;
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
