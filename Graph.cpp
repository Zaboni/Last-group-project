#include "Graph.h"

Graph::Graph() { // Default constructor
    V = 0;
}

Graph::Graph(int V) { // Constructor with parameter to set number of vertices
    this->V = V + 1; // We are traversing from 1 so we need to add 1 to V
    adj = new Node*[V];
    for (int i = 1; i < V; ++i) {
        adj[i] = nullptr;
    }
    
}

Graph::Graph(const Graph &other) : V(other.V), adj(new Node*[other.V]) {
    for (int i = 1; i < V; ++i) {
        // Copying the linked lists if 'other.adj' has nodes
        if (other.adj[i] != nullptr) {
            adj[i] = new Node(*(other.adj[i]));
        } else {
            adj[i] = nullptr;
        }
    }
}

Graph& Graph::operator=(const Graph &other) {
    if (this != &other) {
        Node** temp = new Node*[other.V];
        for (int i = 1; i < other.V; ++i) {
            // Copying the linked lists if 'other.adj' has nodes
            if (other.adj[i] != nullptr) {
                temp[i] = new Node(*(other.adj[i]));
            } else {
                temp[i] = nullptr;
            }
        }
        delete[] adj;
        adj = temp;
        V = other.V;
    }
    return *this;
}

Graph::~Graph() {
    for (int i = 0; i < V; ++i) { // Delete all the nodes, even though 0 should be nullptr we will check anyway
        Node* current = adj[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->getNext();
            delete temp;
        }
    }
    delete[] adj;
}

void Graph::addEdge(int v, int w) {
    Node* newNode = new Node(w);
    newNode->setNext(adj[v]);
    adj[v] = newNode;
}

Node* Graph::getAdjacency(int v) {
    return adj[v];
}

void Graph::BFS(int s) {
    bool *visited = new bool[V];
    for (int i = 1; i < V; i++) //initialize the visited list to false
        visited[i] = false;

    std::queue<int> queue;  // Create a queue for BFS
    visited[s] = true;
    queue.push(s);
    Node* iter;
    while (!queue.empty()) {
        s = queue.front();
        queue.pop();

        for (iter = adj[s]; iter != nullptr; iter = iter->getNext()) {
            if (!visited[iter->getData()]) {
                visited[iter->getData()] = true;
                queue.push(iter->getData());
            }
        }
    }

    delete[] visited;
}

void Graph::printBFS(int s) {
    BFS(s);
    for (int i = 1; i < V; i++) {
        std::cout << "Vertex " << i << ": ";
        if (i == s) {
            std::cout << "Source" << std::endl;
        } else if (adj[i] == nullptr) {
            std::cout << "Not Reacheable by any nodes" << std::endl;    
        } else {
            std::cout << "Reachable from ";
            Node* iter;
            for (iter = adj[i]; iter != nullptr; iter = iter->getNext()) {
                std::cout << iter->getData() << " ";
            }
            std::cout << std::endl;           
        }
    }
}

int minDistance(const std::vector<int>& dist, const std::vector<bool>& visited) {
    int min = std::numeric_limits<int>::max();
    int min_index = -1;

    for (int v = 0; v < dist.size(); v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void Graph::printShortestPath(int s, int v) {
    std::vector<int> dist(V, std::numeric_limits<int>::max());
    std::vector<bool> visited(V, false);
    std::vector<int> pred(V, -1);

    dist[s] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);
        visited[u] = true;
        for (Node* node = adj[u]; node != nullptr; node = node->getNext()) {
            int weight = 1; // Assuming a constant weight of 1 for all edges.
            int alt = dist[u] + weight;
            int neighbor = node->getData();
            if (!visited[neighbor] && alt < dist[neighbor]) {
                dist[neighbor] = alt;
                pred[neighbor] = u;
            }
        }
    }

    std::cout << "Shortest path from " << s << " to " << v << ": ";
    if (pred[v] == -1) {
        std::cout << "No path exists" << std::endl;
    } else {
        for (int cur = v; cur != s; cur = pred[cur]) {
            std::cout << cur << " <- ";
        }
        std::cout << s << std::endl;
    }
}
