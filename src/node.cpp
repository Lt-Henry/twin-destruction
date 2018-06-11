
#include "node.hpp"

using namespace twin;
using namespace std;


Node::Node(string name,Node* parent)
{
    this->parent=parent;
    this->name=Name(name);
}

Node::~Node()
{
    // destroy children?
}
