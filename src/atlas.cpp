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
 

#include "atlas.hpp"
#include "game.hpp"

#include <SDL2/SDL_image.h>

using namespace twin;
using namespace std;

Atlas::Atlas(string filename,string name) : Node(name,"atlas")
{
    SDL_Renderer* renderer=Game::get()->get_context();
    
    SDL_Surface* data = IMG_Load(filename);
    this->texture = SDL_CreateTextureFromSurface(renderer,data);
    
    SDL_FreeSurface(data);
}

Atlas::~Atlas()
{
    SDL_DestroyTexture(this->texture);
}

SDL_Texture* Atlas::get_texture()
{
    return this->texture;
}
