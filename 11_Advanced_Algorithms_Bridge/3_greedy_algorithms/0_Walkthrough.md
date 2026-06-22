# Walkthrough: Greedy Algorithms

Greedy algorithms build up a solution piece by piece, always choosing the next piece that offers the most immediate benefit.

## Core Principle
"At every step, make the locally optimal choice, hoping it leads to a globally optimal solution."

## When does it work?
Greedy algorithms only work when the problem has the **Greedy-Choice Property**: a global optimum can be arrived at by selecting a local optimum. 
* If you want to find the shortest path on a map, taking the shortest available road at each intersection *usually* gets you there fastest.

## DP vs Greedy
* **Greedy:** Takes the best immediate choice and never looks back. (Faster, but doesn't always guarantee correct optimal solution for all problems).
* **DP:** Explores all possible choices and their consequences before making a decision. (Slower, but guaranteed optimal).

## Famous Greedy Algorithms
* **Dijkstra's Algorithm:** Finding the shortest path from a source to all other nodes in a graph.
* **Kruskal's & Prim's Algorithms:** Finding the Minimum Spanning Tree of a graph.
* **Fractional Knapsack:** Unlike the 0/1 Knapsack (which requires DP), if you can break items into fractions, you simply take the items with the highest value-to-weight ratio first!
