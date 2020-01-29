//
// Created by parallels on 1/29/20.
//

#ifndef DNASEQUENCE_FILE_H
#define DNASEQUENCE_FILE_H

#include <string>

class File {
public:
    File() {};

    ~File() {};

    std::string readFile(const char *fileName);

    void writeFile(const char *fileName, const char data[]);
};

#endif //DNASEQUENCE_FILE_H
