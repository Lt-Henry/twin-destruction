
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
