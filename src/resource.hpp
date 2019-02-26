
#ifndef TWIN_RESOURCE
#define TWIN_RESOURCE

#include "node.hpp"

namespace twin
{
    enum class ResourceError 
    {
        Parse
    };
    
    class Resource: public Node
    {
        public:
        
        
        Resource(const char* filename);
        
    };
}

#endif
