
#ifndef TWIN_NAME
#define TWIN_NAME

#include <vector>
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
        size_t get_hash();
        
        bool equal(const Name& n);
        bool equal(const std::string& s);
        
        bool operator == (const Name& b);
        bool operator != (const Name& b);
        
        bool operator == (const std::string& b);
        bool operator != (const std::string& b);
    };
    
    class Path
    {
        public:
        
        std::vector<Name> dirs;
        
        Path(std::string path);
    };
}

#endif
