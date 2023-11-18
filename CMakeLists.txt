cmake_minimum_required(VERSION 3.26)
project(Projeto)

set(CMAKE_CXX_STANDARD 17)

add_executable(Projeto src/main.cpp
        src/Solution.cpp
        src/Solution.h
        src/Greedy.cpp
        src/Greedy.h
        src/IO.cpp
        src/IO.h
        src/Data.cpp
        src/Data.h
        src/VND.cpp
        src/VND.h
        src/LocalSearch.cpp
        src/LocalSearch.h
)
