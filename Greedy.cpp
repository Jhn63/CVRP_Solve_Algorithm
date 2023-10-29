//
// Created by JHN on 18/10/2023.
//

#include <iostream>
#include "Greedy.h"

Greedy::Greedy(Data *data) : data(data), v_count(1) {
    s = new Solution(); //solução vazia
    visited = new std::vector<uint8_t>(data->n +1); // + uma posição para o deposito, que será irrelevante
    for (auto e : *visited) {
        e = false;
    }
    auto it = visited->begin(); *it = true;
}

Greedy::~Greedy() {
    delete visited;
}

Solution *Greedy::create() {
    while (!complete()) {

        if (v_count < data->L) {
            //não pode terceirizar
            s->vehicle_use_cost += data->r;
            s->routes.push_back(create_route());
        }
        else {
            //pode terceirizar
            int trash = 0;
            int i = cheapest_not_visited_point(data->route_c[0], &trash);
            if (data->route_c[0][i] < data->outsourcing[i] && v_count < visited->size() -1) {
                //não terceirizar
                s->vehicle_use_cost += data->r;
                s->routes.push_back(create_route());
            }
            else {
                //terceirizar
                auto v = visited->begin() + i;
                *v = true; v_count++;
                s->outsourcing_use_cost += data->outsourcing[i];
                s->outs_attended_client.push_back(i);
            }
        }
    }

    s->attended_c = v_count;
    s->sum_cost();
    return s;
}

std::vector<int> Greedy::create_route() {
    std::vector<int> route;
    route.push_back(0);
    int vehicle_q = 0;
    while (true) {
        auto it = data->route_c[route.back()];

        int i = cheapest_not_visited_point(it, &vehicle_q);
        if (vehicle_q > data->Q || i == 0) {
            route.push_back(0);
            s->route_cost += it[0];
            break;
        }
        else {
            auto v = visited->begin() + i;
            *v = true; v_count++;
            route.push_back(i);
            s->route_cost += it[i];
        }
    }
    return route;
}

//não verifica o valor do deposito pq é sempre false
int Greedy::cheapest_not_visited_point(std::vector<int> edge_c, int *vehicle_q) {
    int index = 0;
    int minimum = INT_MAX;
    for (int i = 0; i < edge_c.size(); i++) {
        if (edge_c[i] == 0) { continue; }

        if (*vehicle_q < data->Q) {

            uint8_t v =  visited->at(i);
            if (edge_c[i] < minimum && !v) {
                index = i;
                minimum = edge_c[i];
            }
        }
    }
    *vehicle_q += data->demand[index];
    return index;
}

bool Greedy::complete() {
    if (v_count == visited->size() ) {
        return true;
    }
    return false;
}