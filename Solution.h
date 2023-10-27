//
// Created by JHN on 18/10/2023.
//

#ifndef PROJETO_SOLUTION_H
#define PROJETO_SOLUTION_H

#include <vector>

class Solution {
public:
    int attended_c; //numero de clientes atendidos sem terceirização
    int total_cost;
    int route_cost;
    int vehicle_use_cost;
    int outsourcing_use_cost;

    int route_quantity;
    std::vector<std::vector<int>> routes;
    std::vector<int> outs_attended_client;

    Solution() : attended_c(0), total_cost(0), route_cost(0), vehicle_use_cost(0), outsourcing_use_cost(0), route_quantity(0) {};
    void sum_cost();
};


#endif //PROJETO_SOLUTION_H
