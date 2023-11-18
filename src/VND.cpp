//
// Created by JHN on 26/10/2023.
//

#include <iostream>
#include "VND.h"

VND::VND(Data *d, Solution *s) {
    this->s = s;
    ls = new LocalSearch(d,s);
}
VND::~VND() {
    delete ls;
}

void VND::start() {
    int i;
    int count = 1;
    while (count <= 4) {
        switch (count) {
            case 1: {
                i = ls->swap();
                break;
            }
            case 2: {
                i = ls->reinsert_outs();
                break;
            }
            case 3: {
                i = ls->crossover();
                break;
            }
            case 4: {
                i = ls->reinsert_route();
            }
        }
        if (!i) { count++; } else { count = 1; }
    }
}



