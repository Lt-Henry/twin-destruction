
#ifndef TWIN_NAME
#define TWIN_NAME

#include <functional>
#include <string>

namespace twin
{
    class Name
    {
        private:
        
        std::string str;
        size_t hsh;
        
        public:
        
        Name();
        Name(std::string name);
        
        std::string get_name();
        
        bool operator == (const Name& b);
        bool operator != (const Name& b);
    };
}

#endif
