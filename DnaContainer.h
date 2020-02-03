//
// Created by parallels on 2/2/20.
//

#ifndef DNASEQUENCE_DNACONTAINER_H
#define DNASEQUENCE_DNACONTAINER_H

#include <cstddef>
#include <vector>
#include <utility>
#include "MetaDnaSequence.h"
#include <map>


class DnaContainer {
public:
    static void addDna(size_t id, MetaDnaSequence *metaDnaSequence);

    static std::vector<std::pair<size_t, MetaDnaSequence *> > getContainer();

    static MetaDnaSequence findById(size_t id);

private:
    static std::vector<std::pair<size_t, MetaDnaSequence *> > s_container;
};

#endif //DNASEQUENCE_DNACONTAINER_H
