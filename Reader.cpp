//
// Created by JHN on 18/10/2023.
//


#include "Reader.h"

Data *Reader::read_data(const std::string file_path) {
    std::ifstream input;
    input.open(file_path);
    if(!input.is_open()) {
        std::cerr << "Erro ao abrir arquivo" << std::endl;
        exit(-1);
    }

    int num;
    std::string line;

    //lendo parametros
    int n, k, Q, L, r;
    input >> n; input >> k;
    input >> Q; input >> L; input >> r;
    Data *data = new Data(n, k , r, Q, L);

    //lendo arrays
    for (int i = 1; i <= 2; ) {

        std::getline(input, line);
        if (!line.empty()) {

            std::istringstream stream(line);
            while(stream >> num) {
                if (i == 1)  { data->demand.push_back(num); }
                else    { data->outsourcing.push_back(num); }
            }
            i++;
        }
    }

    //lendo matriz
    while (!input.eof()) {
        std::getline(input, line);
        if (!line.empty()) {

            std::vector<int> intern;
            std::istringstream stream(line);
            while (stream >> num) {
                intern.push_back(num);
            }
            data->route_c.push_back(intern);
        }
    }
    input.close();
    return data;
}