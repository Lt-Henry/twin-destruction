
#include "node.hpp"

using namespace twin;
using namespace std;


Node::Node(string name,Node* parent)
{
    this->parent=parent;
    this->name=Name(name);
}

Node::Node(string name,string type,Node* parent)
{
    this->parent=parent;
    this->name=Name(name);
    this->type=Name(type);
}

Node::~Node()
{
    // recursive children tree destruction
    for (Node* node : children) {
        delete node;
    }
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

void Node::add(Node* node)
{
    children.push_back(node);
}

void Node::remove(Node* node)
{
    unsigned int n;
    
    for (n=0;n<children.size();n++) {
        if (children[n]==node) {
            children.erase(children.begin()+n);
            break;
        }
    }
}
