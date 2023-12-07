#ifndef GRAPH_H
#define GRAPH_H

#include "Node.h"
#include <queue>
#include <iostream>

class Graph {
public:
    Graph(); // Default constructor
    Graph(int V); // Constructor
    Graph(const Graph& other); // Copy constructor
    Graph& operator=(const Graph& other); // Assignment operator
    ~Graph(); // Destructor

    void addEdge(int v, int w); // Function to add an edge to graph
    void BFS(int s); // BFS traversal from a given source s
    void printBFS(int s); // Print BFS tree from a given source
    void printShortestPath(int s, int v); // Print shortest path from s to v

private:
    int V; // No. of vertices
    Node** adj; // Pointer to an array containing adjacency lists
};

#endif // GRAPH_H