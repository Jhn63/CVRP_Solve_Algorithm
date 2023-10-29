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
        if (!i) { count++; } else {
            std::cout << "method " << count << " used" << std::endl;
            std::cout << "VND " << std::endl;
            std::cout << s->total_cost << std::endl;
            std::cout << s->route_cost << std::endl;
            std::cout << s->vehicle_use_cost << std::endl;
            std::cout << s->outsourcing_use_cost << std::endl << std::endl;

            for (auto e : s->outs_attended_client) {
                std::cout << e << " ";
            }
            std::cout << std::endl << std::endl;

            std::cout << s->routes.size() << std::endl;
            for (const auto& it : s->routes) {
                for (auto e : it) {
                    std::cout << e << " ";
                }
                std::cout << std::endl;
            }
            std::cout << std::endl << std::endl;
            count = 1;
        }
    }
}



