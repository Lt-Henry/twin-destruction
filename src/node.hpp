
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
        
        Node* parent;
        
        std::vector<Node*> children;
        
        Node(std::string name,Node* parent=nullptr);
        
        virtual ~Node();
        
        /*!
            Get first match from local children
        */
        Node* first(Name& name);
        
        /*!
            Add node as local child
        */
        void add(const Node* node);
        
        /*!
            Remove node from local children
        */
        void remove(const Node* node);
        
    };
}

#endif
