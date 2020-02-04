
#include "node.hpp"

using namespace twin;
using namespace std;

Node _root("root","dir",nullptr);

Node::Node(string name,Node* parent)
{
    this->name=Name(name);
    
    if (parent!=nullptr) {
        parent->add(this);
    }
}

Node::Node(string name,string type,Node* parent)
{
    this->name=Name(name);
    this->type=Name(type);
    
    if (parent!=nullptr) {
        parent->add(this);
    }
}

Node::~Node()
{
    // recursive children tree destruction
    for (Node* node : children) {
        delete node;
    }
}

Node* Node::root()
{
    return &_root;
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
    node->parent=this;
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

void Node::create_path(Path path)
{
    Node* current=this;
    
    for (Name& dir:path.dirs) {
        
        Node* found=nullptr;
        
        for (Node* child: current->children) {
            if (child->name==dir) {
                if (child->type=="dir") {
                    found=child;
                    break;
                }
                else {
                    //error, path already exists and it is not a dir
                    return;
                }
            }
        }
        
        if (found!=nullptr) {
            current=found;
        }
        else {
            current->add(new Node(dir.get_name(),"dir"));
        }
    }
}