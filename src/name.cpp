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

Path::Path(const char* path) : Path(string(path))
{
}

std::ostream& operator<<(std::ostream& os,twin::Name& name)
{
    os<<name.get_name();
    return os;
}
