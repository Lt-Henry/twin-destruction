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
 
#ifndef TWIN_NODE
#define TWIN_NODE

#include "name.hpp"

#include <vector>
#include <string>

namespace twin
{
    class Node
    {
        public:
        
        Name name;
        Name type;
        
        Node* parent;
        
        std::vector<Node*> children;
        
        Node(std::string name,Node* parent=nullptr);
        Node(std::string name,std::string type,Node* parent=nullptr);
        
        virtual ~Node();
        
        static Node* root();
        
        /*!
            Get first match from local children
        */
        Node* first(Name& name);
        
        /*!
            Add node as local child
        */
        void add(Node* node);
        
        /*!
            Remove node from local children
        */
        void remove(Node* node);
        
        void create_path(Path path);
    };
}

#endif
