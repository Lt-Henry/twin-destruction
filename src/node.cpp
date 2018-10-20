
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

Node* Node::first(Name& name)
{
    Node* match = nullptr;
    
    for (Node* node : children) {
        if (node->name==name) {
            match=node;
            break;
        }
    }
    
    return match;
}

void Node::add(const Node* node)
{
    children.add(node);
}

void Node::remove(const Node* node)
{
    int n;
    
    for (n=0;n<children.size();n++) {
        if (children[n]==node) {
            children.erase(children.begin()+n);
            break;
        }
    }
}
