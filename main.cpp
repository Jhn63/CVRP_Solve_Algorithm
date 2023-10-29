#include <iostream>

#include "VND.h"
#include "Greedy.h"
#include "Reader.h"


int main() {
    Reader reader;
    Data *data = reader.read_data("C:\\Users\\Melissa\\Documents\\UFPB\\5# Periodo\\Analise e Projeto de Algoritmos\\instancias\\instancias\\n31k5_A.txt");
    Greedy greedy(data);
    Solution *s = greedy.create();

    std::cout << "Guloso 1" << std::endl;
    std::cout << s->total_cost << std::endl;
    std::cout << s->route_cost << std::endl;
    std::cout << s->vehicle_use_cost << std::endl;
    std::cout << s->outsourcing_use_cost << std::endl << std::endl;

    for (auto e : s->outs_attended_client) {
        std::cout << e << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << s->routes.size() << std::endl;
    for (const auto& it : s->routes) {
        for (auto e : it) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;

    VND vnd1(data, s);
    vnd1.start();

    std::cout << "VND " << std::endl;
    std::cout << s->total_cost << std::endl;
    std::cout << s->route_cost << std::endl;
    std::cout << s->vehicle_use_cost << std::endl;
    std::cout << s->outsourcing_use_cost << std::endl << std::endl;

    for (auto e : s->outs_attended_client) {
        std::cout << e << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << s->routes.size() << std::endl;
    for (const auto& it : s->routes) {
        for (auto e : it) {
            std::cout << e << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl;
}