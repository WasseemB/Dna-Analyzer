//
// Created by parallels on 2/2/20.
//

#ifndef DNASEQUENCE_ERRORCOMMAND_H
#define DNASEQUENCE_ERRORCOMMAND_H

#include <vector>
#include "Command.h"

class ErrorCommand : public Command {
public:
    ErrorCommand(std::vector<std::string> args);

    void run();

private:
    std::vector<std::string> m_args;

};

#endif //DNASEQUENCE_ERRORCOMMAND_H
