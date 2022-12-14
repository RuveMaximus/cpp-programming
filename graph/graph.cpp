#include <iostream>
#include "graph.hpp"


Graph::Graph()
{
    std::cout << "Create graph..." << this << std::endl;
}
Graph::Graph(int size)
{
    std::cout << "Created graph with size..." << this << std::endl;
}
Graph::~Graph()
{
    std::cout << "Delete graph..." << this << std::endl;
}

void Graph::add_node(const Node& node)
{
    this.nodes.push_back(node);
}


void print(const Graph& graph)
{
    std::cout << "Graph size: " << graph.size() << std::endl;
}