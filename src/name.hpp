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
 
#ifndef TWIN_NAME
#define TWIN_NAME

#include <vector>
#include <string>

namespace twin
{
    class Name
    {
        protected:
        
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
