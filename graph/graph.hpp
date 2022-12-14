#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>


class Node
{
private:
    std::vector<int> connections;

public:
    Node();
    ~Node(); 

    friend void print(const Node&);
}


class Graph
{
private:
    std::vector<Node> nodes;

public:
    Graph();
    Graph(int size); 
    ~Graph();

    void add_node(const Node&);

    friend void print(const Graph&); 
}

#endif