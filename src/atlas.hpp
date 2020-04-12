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
 

#ifndef TWIN_ATLAS
#define TWIN_ATLAS

#include "node.hpp"

#include <SDL2/SDL.h>

#include <map>
#include <string>

namespace twin
{
    
    class Atlas : public Node
    {
        public:
        
        SDL_Texture* texture;

        Atlas(std::string filename, std::string name);
        virtual ~Atlas();
        
        void create_sprite(int w,int h,int c,int r,std::string name);
    };
}

#endif
