#include <iostream>
#include "graph.hpp"

Node::Node()
{
    std::cout << "Create Node..." << this << std::endl;
}
Node::~Node()
{
    std::cout << "Delete Node..." << this << std::endl;
} 


print(const Node& node)
{
    for (int i = 0; i < node.connections.size(); ++i)
    {
        std::cout << node.connections[i] << std::endl;
    }
}
