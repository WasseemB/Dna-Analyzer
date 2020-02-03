//
// Created by parallels on 1/29/20.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "File.h"

using namespace std;

std::string File::readFile(const char *fileName) {
    string line;
    stringstream ss;
    ifstream infile;
    infile.open(fileName);
    while (!infile.eof()) // To get you all the lines.
    {
        getline(infile, line); // Saves the line in STRING.
        ss << line; // Prints our STRING.
    }
    infile.close();
    return ss.str();
}

bool File::exists(const std::string &name) {
    if (FILE *file = fopen(name.c_str(), "r")) {
        fclose(file);
        return true;
    } else {
        return false;
    }
}

void File::writeFile(const char *fileName, const char *data) {
    ofstream outputFile;
    outputFile.open(fileName);
    outputFile << data;
    outputFile.flush();
    outputFile.close();
}
