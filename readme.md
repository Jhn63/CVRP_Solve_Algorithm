# CVRP SOLVER

## An algorithm  to solve a Capacitated Vehicle Routing Problem proposed at UFPB

This is a heuristic algorithm to optimize the cost of vehicle routing fleets, as a heuristic
approach is not guarantee to found the better solution. The project is divided into the following parts

* Constructive Algorithm <br>
 The nearest neighbor was initially use as greedy approach to generate a base solution


* Variable Neighborhood Descent <br>
VND uses four local search structures to optimize the previous solution give by the greedy algorithm


* Meta heuristic <br>
is a technique to avoid minimal local and provides a better exploration of the solution space.
Due to a deadline, no meta heuristic could to be implemented.


## The Problem
The especificacao.pdf file in the root directory explains the problem (is written in Portuguese),
gave parameters, and is a guide to the implementation.

In the same folder a PDF called relatorio can be found, it's a table in which the first two columns
lead to the instance name and its optimal solution, both given in classes.
The following columns are related to the greedy algorithm and VND, each one has a total cost solution,
speed time in milliseconds, and a calculated gap between the optimal and founded costs

## Input and Output Files
The program waits for a text file written in a specific format (see espeficicacao.pdf),
by the end, another text file is written containing the details about the solution.

Every instance file can be found in the folder "instancias" and solutions files in "solucoes",
both inside cmake-build-debug folder