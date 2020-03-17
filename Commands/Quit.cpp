//
// Created by Wasseem Bazbaz on 16/03/2020.
//

#include <iostream>
#include "Quit.h"
#include "../DnaContainer.h"

using namespace std;
const string Quit::s_HELP = "quit";
const string Quit::s_INFO = "prints a goodbye message and exists the application.";

std::string Quit::getHelp() {
    return Quit::s_HELP;
}

std::string Quit::getInfo() {
    return Quit::s_INFO;
}

void Quit::run(std::vector<std::string> args) {
    size_t countMod = 0;
    size_t countNew = 0;
    size_t countUp = 0;

    // no where near done
    map<size_t, RealDnaSequence *>::iterator it;
    for (it = DnaContainer::getContainer().begin(); it != DnaContainer::getContainer().end(); it++) {
        switch (it->second->getStatus()) {
            case NEW: {
                countNew++;
                break;
            }
            case MODIFIED: {
                countMod++;
                break;
            }
            case UP_TO_DATE: {
                countUp++;
                break;
            }

        }
    }
    if (countMod + countUp > 0)
        cout << "There are " << countMod << "modified and " << countNew
             << " new sequences. Are you sure you want to quit?\n"
                "Please confirm by 'y' or 'Y', or cancel by 'n' or 'N'."
             << endl;
    else
        cout << "Thank you for using Dnalanyzer. \n"
                "Goodbye!" << endl;
}
