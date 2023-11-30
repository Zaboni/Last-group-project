#include "Graph.h"

int main() {
    Graph g(6); // Create a graph with 6 vertices

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    int source = 0; // Source vertex for BFS
    std::cout << "BFS from vertex " << source << ":" << std::endl;
    g.printBFS(source); // Print BFS tree

    int destination = 4; // Destination vertex for shortest path
    std::cout << "\nShortest path from " << source << " to " << destination << ":" << std::endl;
    g.printShortestPath(source, destination); // Print shortest path

    return 0;
}
