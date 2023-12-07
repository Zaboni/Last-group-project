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

void Graph::printShortestPath(int s, int v) {
    if (s == v){
        std::cout << "Shortest path from " << s << " to " << v << " is " << s << std::endl;
    }
    else if (adj[v] == nullptr) {
        std::cout << "No path from " << s << " to " << v << " exists" << std::endl;
    } else {
        printShortestPath(s, v);
        std::cout<< "->" << v;
    }
}
