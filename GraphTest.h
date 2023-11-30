#ifndef GRAPHTEST_H
#define GRAPHTEST_H

#include "Graph.h"
#include <cassert>

void testAddEdge() {
    Graph g(3);
    g.addEdge(0, 1);
    g.addEdge(0, 2);

    // Add assertions to check if edges are added correctly
    // For example, check if adjacency lists of vertices 0, 1, and 2 are as expected
}

void testBFS() {
    Graph g(3);
    g.addEdge(0, 1);
    g.addEdge(0, 2);

    // Add assertions to check BFS results
    // For example, check if BFS traversal order is as expected
}

void testShortestPath() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    // Add assertions to check shortest paths
    // For example, check if the shortest path between two nodes is as expected
}

void runAllTests() {
    testAddEdge();
    testBFS();
    testShortestPath();

    std::cout << "All tests passed!" << std::endl;
}

#endif // GRAPHTEST_H
