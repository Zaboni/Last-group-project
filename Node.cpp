#include "Node.h"

    Node::Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    Node::Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }
    Node::~Node(){
        delete next;
    }
    Node& Node::operator=(const Node& other){
        data = other.data;
        next = other.next;
        return *this;
    }
    int Node::getData(){
        return data;
    }
    void Node::setData(int data){
        this->data = data;
    }
    Node::Node(const Node& other){
        data = other.data;
        next = other.next;
    }
    Node* Node::getNext(){
        return next;
    }
    void Node::setNext(Node* next){
        this->next = next;
    }