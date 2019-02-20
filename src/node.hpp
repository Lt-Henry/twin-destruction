
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
        
    };
}

#endif
