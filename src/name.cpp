
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

bool Name::operator == (const Name& b)
{
    return hsh==b.hsh;
}

bool Name::operator != (const Name& b)
{
    return hsh!=b.hsh;
}

Path::Path(string path)
{
    string tmp;
    
    for (char c:path) {
        if (c=='.') {
            names.push_back(Name(tmp));
            tmp="";
        }
        else {
            tmp+=c;
        }
    }
    
    if (tmp.size()>0) {
        names.push_back(Name(tmp));
    }
}
