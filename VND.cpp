//
// Created by JHN on 26/10/2023.
//

#include <iostream>
#include "VND.h"

VND::VND(Data *d, Solution *s) {
    ls = new LocalSearch(d,s);
}
VND::~VND() {
    delete ls;
}

void VND::start() {
    int i;
    int count = 1;
    while (count <= 2) {
        switch (count) {
            case 1: {
                i = ls->reinsert_route();
                break;
            }
            case 2: {
                i = ls->reinsert_outs();
                break;
            }
        }
        if (!i) { count++; } else {
            std::cout << "method " << count << " used" << std::endl;
            count = 1;
        }
    }
}



