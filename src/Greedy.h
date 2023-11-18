//
// Created by JHN on 18/10/2023.
//

#ifndef PROJETO_GREEDY_H
#define PROJETO_GREEDY_H

#include <cstdint>
#include "Data.h"
#include "Solution.h"

class Greedy {
private:
    Data *data;  //precisar ser um ponteiro?
    Solution *s; // - - - - - - - - - - - -
    int v_count; //contador dos visitados
    std::vector<uint8_t> *visited;

    bool complete();
    std::vector<int> create_route();
    int cheapest_not_visited_point(std::vector<int> edges_cost, int *vehicle_q);

public:
    Greedy(Data *data);
    ~Greedy();
    Solution *create();
};


#endif //PROJETO_GREEDY_H
