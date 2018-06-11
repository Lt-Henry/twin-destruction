
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
        
        Node* first(std::string name);
        
    };
}

#endif
