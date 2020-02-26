//
// Created by parallels on 2/2/20.
//

#ifndef DNASEQUENCE_DNACONTAINER_H
#define DNASEQUENCE_DNACONTAINER_H

#include <cstddef>
#include <vector>
#include <utility>
#include "Model/RealDnaSequence.h"
#include <map>


class DnaContainer {
public:
    static void addDna(size_t id, RealDnaSequence *metaDnaSequence);

    static std::map<size_t, RealDnaSequence *> getContainer();

    static RealDnaSequence *findById(size_t id);

private:
    static std::map<size_t, RealDnaSequence *> s_container;
};

#endif //DNASEQUENCE_DNACONTAINER_H
