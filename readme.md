# CVRP SOLVER

## An algorithm  to solve a Capacitated Vehicle Routing Problem proposed at UFPB

This is a heuristic algorithm to optimize the cost of vehicle routing fleets, as a heuristic
approach is not guarantee to found the better solution. The project is divided in the following parts

* Constructive Algorithm <br>
 The nearest neighbor was initially use as greedy approach to generate a base solution


* Variable Neighborhood Descent <br>
VND uses four local search structures to optimize the previous solution give by the greedy algorithm


* Meta heuristic <br>
is a technique that avoid minimal local and provides a better exploration of the solution space.
Due to deadline, no meta heuristic could to be implemented.