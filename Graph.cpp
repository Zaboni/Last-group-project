#include "Graph.h"

Graph::Graph(int V) {
    this->V = V;
    adj = new std::list<int>[V];
}

Graph::Graph(const Graph &other) {
    V = other.V;
    adj = new std::list<int>[V];
    for (int i = 0; i < V; ++i) {
        adj[i] = other.adj[i];
    }
}

Graph::~Graph() {
    delete[] adj;
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v); // Assuming undirected graph
}

void Graph::BFS(int s) {
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    std::queue<int> queue;
    visited[s] = true;
    queue.push(s);

    while (!queue.empty()) {
        s = queue.front();
        queue.pop();

        for (auto i = adj[s].begin(); i != adj[s].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push(*i);
            }
        }
    }

    delete[] visited;
}

void Graph::printBFS(int s) {
    BFS(s);
    std::cout << std::endl;
}

void Graph::printShortestPath(int s, int v) {
    bool *visited = new bool[V];
    std::vector<int> parent(V, -1);

    BFSUtil(s, visited, parent);
    printPathRecursive(s, v, parent);

    delete[] visited;
}

void Graph::BFSUtil(int s, bool visited[], std::vector<int>& parent) {
    std::queue<int> queue;
    visited[s] = true;
    queue.push(s);

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();

        for (auto v = adj[u].begin(); v != adj[u].end(); ++v) {
            if (!visited[*v]) {
                visited[*v] = true;
                parent[*v] = u;
                queue.push(*v);
            }
        }
    }
}

void Graph::printPathRecursive(int s, int v, std::vector<int>& parent) {
    if (v == s) {
        std::cout << s << " "; // Print source vertex
    } else if (parent[v] == -1) {
        std::cout << "No path from " << s << " to " << v << " exists" << std::endl;
    } else {
        printPathRecursive(s, parent[v], parent); // Recursive call for the predecessor
        std::cout << v << " "; // Print the current vertex
    }
}
