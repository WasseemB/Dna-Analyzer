//
// Created by parallels on 2/4/20.
//

#include <iostream>
#include "DecoratorDnaSequence.h"

void DecoratorDnaSequence::execute() {
    m_iDna->execute();
    std::cout << "Decorator execute " << std::endl;
}
