//
// Created by Melissa on 27/10/2023.
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

public:
    LocalSearch(Data *d, Solution *s) : data(d), s(s) {};

    int reinsert_outs();
    int reinsert_route();
};


#endif //PROJETO_LOCALSEARCH_H
