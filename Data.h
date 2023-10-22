//
// Created by JHN on 18/10/2023.
//

#ifndef PROJETO_DATA_H
#define PROJETO_DATA_H

#include <vector>

//devo utilizar todos os veiculos?
class Data {
public:
    const int n; // numero de clientes
    const int k; // numero de veículos
    const int r; // custo do uso do veículo
    const int Q; // capacidade máxima do veículo
    const int L; // numero mínimo de entregas autorais

    std::vector<int> demand;    // demanda dos clientes
    std::vector<int> outsourcing;   // preço da terceirização
    std::vector<std::vector<int>> route_c;  // matrix de custo de roteamento

    Data(int n, int k, int r, int Q, int L) : n(n), k(k), r(r), Q(Q), L(L) {
        demand.push_back(0);
        outsourcing.push_back(0);
    };
};


#endif //PROJETO_DATA_H
