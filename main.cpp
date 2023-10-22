#include <iostream>

#include "Greedy.h"
#include "Reader.h"

int main() {
    Reader reader;
    Data *data = reader.read_data("C:\\Users\\Melissa\\Documents\\UFPB\\5# Periodo\\Analise e Projeto de Algoritmos\\Projeto\\test.txt");

    Greedy greedy(data);
    Solution *s = greedy.create();

    std::cout << s->total_cost << std::endl;
    std::cout << s->route_cost << std::endl;
    std::cout << s->vehicle_use_cost << std::endl;
    std::cout << s->outsourcing_use_cost << std::endl << std::endl;

    for (auto e : s->outs_attended_client) {
        std::cout << e << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << s->route_quantity << std::endl;
    for (const auto& it : s->routes) {
        for (auto e : it) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }
}