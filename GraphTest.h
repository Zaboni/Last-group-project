#ifndef GRAPHTEST_H
#define GRAPHTEST_H

#include "Graph.h"
#include <cassert>
#include <iostream>

void testAddEdge() {
    Graph g(4); // Starting indexing from 1, the size should be 4 for vertices 1 to 3.

    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    // Testing if edges are added correctly by checking the adjacency lists of vertices.
    assert(g.getAdjacency(1)->getData() == 3); // Expected adjacency list of 1: 3, 2
    assert(g.getAdjacency(2)->getData() == 4); // Expected adjacency list of 2: 4
    assert(g.getAdjacency(3) == nullptr); // Expected adjacency list of 3: nullptr
    assert(g.getAdjacency(4) == nullptr); // Expected adjacency list of 4: nullptr
}

void testBFS() {
    Graph g(4);

    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    // Testing BFS traversal order.
    // You can manually check the printed order with the expected BFS traversal.
    // INCOMPLETE
}

void testShortestPath() {
    Graph g(5);

    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    // Testing shortest paths between vertices.
    std::cout << "Shortest path between 1 and 5: ";
    g.printShortestPath(1, 5);
    std::cout << std::endl;
    // You can manually check the printed shortest path with the expected result.
    // INCOMPLETE
}

void runAllTests() {
    testAddEdge();
    testBFS();
    testShortestPath();

    std::cout << "All tests passed!" << std::endl;
}


#endif // GRAPHTEST_H
