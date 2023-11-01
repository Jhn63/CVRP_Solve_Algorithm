#include <iostream>
#include <chrono>

#include "VND.h"
#include "Greedy.h"
#include "IO.h"

/* FALTA:
 * 1 - arquivo de saida com resultados
 * 2 - tabela de resultados
 * 3 - GAP entre meu resultado e o do professor
 * */

int main() {
    std::string name;

    while (true) {
        std::cout << "type \"sair\" to close" << std::endl;
        std::cout << "file name: ";
        std::cin >> name;

        if (name == "sair") { break; }

        IO io;
        Data *data = io.read_data("instancias\\" + name);
        Greedy greedy(data);

        auto start_time1 = std::chrono::high_resolution_clock::now();
        Solution *s = greedy.create();
        auto end_time1 = std::chrono::high_resolution_clock::now();
        auto duration1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time1 - start_time1);
        double milliseconds1 = duration1.count() / 1000000.0;

        int best1 = s->total_cost;

        VND vnd1(data, s);

        auto start_time2 = std::chrono::high_resolution_clock::now();
        vnd1.start();
        auto end_time2 = std::chrono::high_resolution_clock::now();
        auto duration2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time2 - start_time2);
        double milliseconds2 = duration2.count() / 1000000.0;

        int best2 = s->total_cost;

        io.write_solution(s, "solucoes\\" + name);

        std::cout << std::endl;
        std::cout << "Greedy concluded in: " << milliseconds1 << " ms " << "cost: " << best1 << std::endl;
        std::cout << "VND concluded in: " << milliseconds2 << " ms " << "cost: " << best2 << std::endl;
        std::cout << std::endl;

        delete data;
        delete s;
    }
}