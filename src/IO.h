//
// Created by JHN on 18/10/2023.
//

#ifndef PROJETO_IO_H
#define PROJETO_IO_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Data.h"
#include "Solution.h"

class IO {
public:
    Data *read_data(std::string file_path);
    void write_solution(Solution *s, std::string file_name);
};


#endif //PROJETO_IO_H
