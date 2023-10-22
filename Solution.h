//
// Created by JHN on 18/10/2023.
//

#ifndef PROJETO_SOLUTION_H
#define PROJETO_SOLUTION_H

#include <list>

class Solution {
public:
    int total_cost;
    int route_cost;
    int vehicle_use_cost;
    int outsourcing_use_cost;

    int route_quantity;
    std::list<std::list<int>> routes;
    std::list<int> outs_attended_client;

    Solution() : total_cost(0), route_cost(0), vehicle_use_cost(0), outsourcing_use_cost(0), route_quantity(0) {};
    void sum_cost();
};


#endif //PROJETO_SOLUTION_H
