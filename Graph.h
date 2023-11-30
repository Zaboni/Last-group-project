#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <vector>
#include <queue>
#include <iostream>

class Graph {
public:
    Graph(int V); // Constructor
    Graph(const Graph& other); // Copy constructor
    ~Graph(); // Destructor

    void addEdge(int v, int w); // Function to add an edge to graph
    void BFS(int s); // BFS traversal from a given source s
    void printBFS(int s); // Print BFS tree from a given source
    void printShortestPath(int s, int v); // Print shortest path from s to v

private:
    int V; // No. of vertices
    std::list<int>* adj; // Pointer to an array containing adjacency lists
    void BFSUtil(int s, bool visited[], std::vector<int>& parent);
    void printPathRecursive(int s, int v, std::vector<int>& parent);
};

#endif // GRAPH_H
