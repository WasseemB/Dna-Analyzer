//
// Created by parallels on 2/2/20.
//

#ifndef DNASEQUENCE_SAVE_H
#define DNASEQUENCE_SAVE_H
#include "Command.h"

class Save : public Command {
public:
    Save(std::vector<std::string> args);

    void run();

private:
    std::vector<std::string> m_args;

};
#endif //DNASEQUENCE_SAVE_H
