cmake_minimum_required(VERSION 3.26)
project(Projeto)

set(CMAKE_CXX_STANDARD 17)

add_executable(Projeto main.cpp
        Solution.cpp
        Solution.h
        Greedy.cpp
        Greedy.h
        IO.cpp
        IO.h
        Data.cpp
        Data.h
        VND.cpp
        VND.h
        LocalSearch.cpp
        LocalSearch.h
)
