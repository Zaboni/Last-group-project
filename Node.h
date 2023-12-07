#ifndef NODE_H
#define NODE_H

class Node{
    private:
        int data;
        Node* next;
    public:
        Node(int data); // Constructor
        Node(int data, Node* next); // Constructor
        ~Node(); // Destructor
        Node(const Node& other); // Copy constructor
        Node& operator=(const Node& other);  // Assignment operator
        int getData(); // Getter
        void setData(int data); // Setter
        Node* getNext(); // Getter
        void setNext(Node* next); // Setter
};
#endif // NODE_H