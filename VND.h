//
// Created by JHN on 26/10/2023.
//

#ifndef PROJETO_VND_H
#define PROJETO_VND_H


#include "LocalSearch.h"

class VND {
private:
   LocalSearch *ls;

public:
    VND(Data *d, Solution *s);
    ~VND();

    void start();
};


#endif //PROJETO_VND_H
