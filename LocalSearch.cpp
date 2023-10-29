//
// Created by JHN on 27/10/2023.
//

#include <iostream>
#include "LocalSearch.h"

//problema quando tem apenas 4 vertices na rota
int LocalSearch::swap() {
    if (s->routes.size() == 0) {
        return 0;
    }
    std::vector<std::vector<int>>::iterator route;
    std::vector<int>::iterator ver;
    std::vector<int>::iterator wer;
    int swap_cost;

    int minimum_c = 0, flag = 0;
    auto it = s->routes.begin();
    for (; it != s->routes.end() ; it++) {

        for (auto v = it->begin()+1 ; v != it->end()-1 ; v++) {
            for (auto w = v+1; w != it->end()-1; w++) {

                int total_c = sw_cost(v, w);
                if (total_c < minimum_c) {
                    minimum_c = total_c;
                    swap_cost = minimum_c;
                    ver = v; wer = w;
                    route = it;
                    flag = 1;
                }
            }
        }
    }
    if (flag) {
        apply_sw(route, ver, wer, swap_cost);
        return 1;
    }
    return 0;
}

int LocalSearch::sw_cost(std::vector<int>::iterator v, std::vector<int>::iterator w) {
    //arestas originais                     //arestas novas
    int e1 = data->route_c[*v][*(v-1)],     a1 = data->route_c[*w][*(v-1)];
    int e2 = data->route_c[*v][*(v+1)],     a2 = data->route_c[*w][*(v+1)];
    int e3 = data->route_c[*w][*(w-1)],     a3 = data->route_c[*v][*(w-1)];
    int e4 = data->route_c[*w][*(w+1)],     a4 = data->route_c[*v][*(w+1)];

    if (v+1 == w and *(v-1) == 0 and *(w+1) == 0) {
        return 0; // não a troca de aresta
    }
    if (*(v-1) == 0 and *(w+1) == 0) {
        return (a2 + a3) - (e2 + e3); //extremos
    }
    if (v+1 == w-1 or v+1 == w) {     //vertice em comum no meio
        return (a1 + a4) - (e1 + e4); //vertices adjacentes
    }
    return (a1+a2+a3+a4) - (e1+e2+e3+e4); //default
}

void LocalSearch::apply_sw(std::vector<std::vector<int>>::iterator route,
std::vector<int>::iterator v, std::vector<int>::iterator w, int cost) {
    std::iter_swap(v,w);
    s->route_cost+= cost;
    s->sum_cost();
}

//é possivel deixar uma rota sem pontos?
int LocalSearch::crossover() {
    if (s->routes.size() < 2) {
        return 0;
    }
    std::vector<std::vector<int>>::iterator route1, route2;
    std::vector<int>::iterator ver, wer;

    int minimum_c = 0, flag = 0;
    for (auto r1 = s->routes.begin() ; r1 != s->routes.end()-1; r1++) {
        for (auto r2 = r1+1 ; r2 != s->routes.end(); r2++) {


            for (auto v = r1->begin() ; v != r1->end() -1; v++) {
                for (auto w = r2->begin() ; w != r2->end() -1 ; w++ ) {

                    if ((*v == 0 and *w == 0) || (*v == 0 and w == r2->end()-2) || (v == r1->end()-2 and *w == 0) ) {
                        continue;
                    }

                    int total_c = edge_result(r1,r2, v, w);
                    if (total_c < minimum_c) {

                        bool flag1 = sight(r1,r2,v,w); //verificando capacidade
                        bool flag2 = sight(r2,r1,w,v);

                        if (flag1 and flag2) {
                            minimum_c = total_c;
                            route1 = r1; route2 = r2;
                            ver = v; wer = w;
                            flag = 1;
                        }
                    }
                }
            }
        }
    }

    if (flag) {
        apply_cr(route1, route2, ver, wer);
        return 1;
    }
    return 0;
}

int LocalSearch::edge_result(std::vector<std::vector<int>>::iterator r1, std::vector<std::vector<int>>::iterator r2,
std::vector<int>::iterator v, std::vector<int>::iterator w) {
    int i = data->route_c[*v][*(v+1)];
    int j = data->route_c[*w][*(w+1)];
    int k = data->route_c[*v][*(w+1)];
    int l = data->route_c[*w][*(v+1)];
    return (k + l) - (i + j);
}

bool LocalSearch::sight(std::vector<std::vector<int>>::iterator r1, std::vector<std::vector<int>>::iterator r2,
std::vector<int>::iterator v, std::vector<int>::iterator w) {
    int vehicle_q = 0;
    auto aux = r1->begin();
    for ( ; aux != r2->end() ; aux++) {
        if (aux == v+1) { aux = w+1; }

        vehicle_q += data->demand[*aux];
        if (vehicle_q > data->Q) { return false; }
    }
    return true;
}

void LocalSearch::apply_cr(std::vector<std::vector<int>>::iterator r1, std::vector<std::vector<int>>::iterator r2,
std::vector<int>::iterator v, std::vector<int>::iterator w) {
    s->route_cost+= (data->route_c[*v][*(w+1)] + data->route_c[*w][*(v+1)]) -
                    (data->route_c[*v][*(v+1)] + data->route_c[*w][*(w+1)]);

    std::vector<int> aux1(v+1, r1->end());
    std::vector<int> aux2(w+1, r2->end());
    r1->erase(v+1, r1->end());
    r1->insert(r1->end(),aux2.begin(), aux2.end());
    r2->erase(w+1, r2->end());
    r2->insert(r2->end(),aux1.begin(), aux1.end());
    s->sum_cost();
}


int LocalSearch::reinsert_route() {
    if (s->outs_attended_client.size() == 0) {
        return 0;
    }
    std::vector<std::vector<int>>::iterator route;
    std::vector<int>::iterator break_p;
    std::vector<int>::iterator ver;

    int minimum_c = 0, flag = 0;
    auto it = s->routes.begin();
    for ( ; it != s->routes.end(); it++) {

        int route_q = 0;
        auto v = it->begin();
        for ( ; v != it->end(); v++) {
            route_q+= data->demand[*v];
        }

        auto w = s->outs_attended_client.begin();
        for ( ; w != s->outs_attended_client.end(); w++) {

            if (route_q + data->demand[*w] <= data->Q) {

                auto u = it->begin();
                for ( ; u != it->end()-1 ; u++) {
                    int i = data->route_c[*u][*w];
                    int j = data->route_c[*(u+1)][*w];
                    int k = data->route_c[*u][*(u+1)];
                    int m = data->outsourcing[*w];

                    int total_c = (i + j) - (k + m);
                    if (total_c < minimum_c) {
                        minimum_c = total_c;
                        break_p = u;
                        route = it;
                        ver = w;
                        flag = 1;
                    }
                }
            }
        }
    }
    if (flag) {
        apply_rr(route, ver, break_p);
        return 1;
    }
    return 0;
}

void LocalSearch::apply_rr
(std::vector<std::vector<int>>::iterator route, std::vector<int>::iterator v, std::vector<int>::iterator w) {
    s->attended_c++;
    s->outsourcing_use_cost-= data->outsourcing[*v];
    s->route_cost+= (data->route_c[*v][*w] + data->route_c[*v][*(w+1)]) - data->route_c[*w][*(w+1)];

    route->insert(w+1,*v);
    s->outs_attended_client.erase(v);
    s->sum_cost();
}


int LocalSearch::reinsert_outs() {
    if (s->attended_c < data->L) {
        return 0;
    }
    std::vector<std::vector<int>>::iterator route;
    std::vector<int>::iterator ver;

    int minimum_c = 0, flag = 0;
    auto it = s->routes.begin();
    for ( ; it != s->routes.end(); it++) {
        auto v = it->begin()+1;
        for ( ; v != it->end()-1; v++) {

            int t = data->outsourcing[*v];              // preço da tercerização de v
            int i = data->route_c[*v][*(v-1)];          // preço da aresta (v,v-1)
            int j = data->route_c[*v][*(v+1)];          // preço da aresta (v,v+1)
            int k = data->route_c[*(v-1)][*(v+1)];      // preço da aresta (v-1,v+1)

            int total_c = (t + k) - (i + j);
            if (total_c < minimum_c) {
                minimum_c = total_c;
                route = it; ver = v;
                flag = 1;
            }
        }
    }
    if (flag) {
        apply_ro(route, ver);
        return 1;
    }
    return 0;
}

void LocalSearch::apply_ro(std::vector<std::vector<int>>::iterator route, std::vector<int>::iterator v) {
    s->attended_c--;
    s->outs_attended_client.push_back(*v);
    s->outsourcing_use_cost+= data->outsourcing[*v];
    s->route_cost+= data->route_c[*(v-1)][*(v+1)] - (data->route_c[*v][*(v-1)] + data->route_c[*v][*(v+1)]);

    route->erase(v);
    if (route->size() < 3) {
        s->routes.erase(route);
        s->vehicle_use_cost-= data->r;
    }
    s->sum_cost();
}