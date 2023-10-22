//
// Created by JHN on 18/10/2023.
//

#ifndef PROJETO_READER_H
#define PROJETO_READER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Data.h"

class Reader {
public:
    Data *read_data(std::string file_path);
};


#endif //PROJETO_READER_H
