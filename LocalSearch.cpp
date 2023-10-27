//
// Created by Melissa on 27/10/2023.
//

#include "LocalSearch.h"

int LocalSearch::reinsert_route() {
    if (s->outs_attended_client.size() == 0) {
        return 0;
    }
    //[0] a rota, [1] vertice a inserir, [2] ponto de quebra
    int apply[3] = {0,0, 0};
    int minimum_c = 0, route_num = 0;

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
                        apply[0] = route_num;
                        apply[1] = *w;
                        apply[2] = *u;
                    }
                }
            }
        }
        route_num++;
    }

    if (apply[1]) {
        auto *outs = &s->outs_attended_client;
        auto w = std::find(outs->begin(), outs->end(), apply[1]);

        auto *e = &s->routes[apply[0]];
        auto u = std::find(e->begin(), e->end(), apply[2]); //pode ter problemas com valores repetidos?

        s->outsourcing_use_cost-= data->outsourcing[*w];
        s->route_cost+= (data->route_c[*u][*w] + data->route_c[*(u+1)][*w]) - data->route_c[*u][*(u+1)];
        *e->insert(u+1, *w);
        s->outs_attended_client.erase(w);
        s->sum_cost();
        s->attended_c++;
        return 1;
    }
    return 0;
}

int LocalSearch::reinsert_outs() {
    if (s->attended_c < data->L) {
        return 0;
    }
    //[0] a rota, [1] o vertice
    int apply[2] = {0,0};
    int minimum_c = 0, route_num = 0;

    auto it = s->routes.begin();
    for ( ; it != s->routes.end(); it++) {

        auto v = it->begin();
        for ( ; v != it->end(); v++) {
            if (*v == 0) { continue; }

            int t = data->outsourcing[*v];        // preço da tercerização de v
            int i = data->route_c[*v][*(v-1)];      // preço da aresta (v,v-1)
            int j = data->route_c[*v][*(v+1)];      // preço da aresta (v,v+1)
            int k = data->route_c[*(v-1)][*(v+1)];    // preço da aresta (v-1,v+1)

            //pega o melhor valor?
            int total_c = (t + k) - (i + j);
            if (total_c < minimum_c) {
                minimum_c = total_c;
                apply[0] = route_num;
                apply[1] = *v;
            }
            v++;
        }
        route_num++;
    }

    if (apply[1]) {
        auto *e = &s->routes[apply[0]];
        auto v = std::find(e->begin(), e->end(), apply[1]);

        s->outs_attended_client.push_back(*v);
        s->outsourcing_use_cost+= data->outsourcing[*v];
        s->route_cost+= data->route_c[*(v-1)][*(v+1)] - (data->route_c[*v][*(v-1)] + data->route_c[*v][*(v+1)]);
        s->sum_cost();
        s->attended_c--;
        e->erase(v);
        return 1;
    }
    return 0;
}