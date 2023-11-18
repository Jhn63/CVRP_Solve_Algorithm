//
// Created by JHN on 27/10/2023.
//

#ifndef PROJETO_LOCALSEARCH_H
#define PROJETO_LOCALSEARCH_H

#include <vector>
#include <algorithm>

#include "Data.h"
#include "Solution.h"

class LocalSearch {
private:
    Data *data;
    Solution *s;

    int sw_cost(std::vector<int>::iterator v, std::vector<int>::iterator w);

    int edge_result(std::vector<std::vector<int>>::iterator r1, std::vector<std::vector<int>>::iterator r2, std::vector<int>::iterator v, std::vector<int>::iterator w);
    bool sight(std::vector<std::vector<int>>::iterator r1, std::vector<std::vector<int>>::iterator r2, std::vector<int>::iterator v, std::vector<int>::iterator w);

    void apply_ro(std::vector<std::vector<int>>::iterator route, std::vector<int>::iterator v);
    void apply_rr(std::vector<std::vector<int>>::iterator route, std::vector<int>::iterator v, std::vector<int>::iterator w);
    void apply_sw(std::vector<std::vector<int>>::iterator route, std::vector<int>::iterator v, std::vector<int>::iterator w, int cost);
    void apply_cr(std::vector<std::vector<int>>::iterator r1, std::vector<std::vector<int>>::iterator r2, std::vector<int>::iterator v, std::vector<int>::iterator w);
public:

    LocalSearch(Data *d, Solution *s) : data(d), s(s) { };

    int swap();
    int crossover();
    int reinsert_outs();
    int reinsert_route();
};


#endif //PROJETO_LOCALSEARCH_H
