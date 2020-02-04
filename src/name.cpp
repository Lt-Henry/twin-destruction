
#include "name.hpp"

using namespace twin;
using namespace std;

Name::Name()
{
}

Name::Name(string name)
{
    str=name;
    hsh=std::hash<string>{}(name);
}

string Name::get_name()
{
    return str;
}

size_t Name::get_hash()
{
    return hsh;
}

bool Name::equal(const Name& n)
{
    return hsh==n.hsh;
}

bool Name::equal(const string& s)
{
    size_t tmp=std::hash<string>{}(s);
    
    return hsh==tmp;
}

bool Name::operator == (const Name& b)
{
    return hsh==b.hsh;
}

bool Name::operator != (const Name& b)
{
    return hsh!=b.hsh;
}

bool Name::operator == (const string& s)
{
    return equal(s);
}

bool Name::operator != (const string& s)
{
    return !equal(s);
}

Path::Path(string path)
{
    string tmp;
    
    for (char c:path) {
        if (c=='.') {
            dirs.push_back(Name(tmp));
            tmp="";
        }
        else {
            tmp+=c;
        }
    }
    
    if (tmp.size()>0) {
        dirs.push_back(Name(tmp));
    }
}
