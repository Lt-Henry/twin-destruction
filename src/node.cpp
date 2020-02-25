/*
 * Copyright (C) 2020 Twin destruction
 *
 * Author:
 *  Enrique Medina Gremaldos <quiqueiii@gmail.com>
 *
 * Source:
 *  https://github.com/Lt-Henry/twin-destruction
 *
 * This file is a part of Twin destruction
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 */
 
#include "node.hpp"

#include <iostream>

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

Node* Node::create_path(Path path)
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
                    cerr<<"error, path already exists and it is not a dir"<<endl;
                    return current;
                }
            }
        }
        
        if (found!=nullptr) {
            current=found;
        }
        else {
            Node* tmp=new Node(dir.get_name(),"dir");
            current->add(tmp);
            current=tmp;
        }
    }
    
    return current;
}

Node* Node::get_path(Path path)
{
    Node* current=this;
    
    for (Name& dir:path.dirs) {
        Node* found = current->first(dir);
        
        if (!found) {
            return nullptr;
        }
        
        current=found;
    }
    
    return current;
}