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
#include "sprite.hpp"
#include "game.hpp"

#include <SDL2/SDL_image.h>

#include <iostream>

using namespace twin;
using namespace std;

Atlas::Atlas(string filename, uint32_t width, uint32_t height, string name) :
    Node(name,"atlas"),
    tile_width(width), 
    tile_height(height)
{
    SDL_Renderer* renderer = Game::get()->renderer;
    SDL_Surface* data = IMG_Load(filename.c_str());
    
    if (!data) {
        cerr<<"Failed to load image:"<<filename<<endl;
    }
    
    this->texture = SDL_CreateTextureFromSurface(renderer,data);
    
    SDL_FreeSurface(data);
}

Atlas::~Atlas()
{
    SDL_DestroyTexture(this->texture);
}

Sprite* Atlas::create_sprite(int c,int r,string name)
{
    return create_sprite(tile_width, tile_height, c, r, name);
}

Sprite* Atlas::create_sprite(int w,int h,int c,int r,string name)
{
    Sprite* sprite;
    
    sprite=new Sprite(this->texture,w,h,c,r,name);
    
    add(sprite);
    
    return sprite;
}

void Atlas::draw(int c, int r, Point position, int z)
{
    SDL_Rect srcrect;
    
    srcrect.w = tile_width;
    srcrect.h = tile_height;
    srcrect.x = tile_width * c;
    srcrect.y = tile_height * r;
    
    Game::draw(texture,srcrect,position,z);
}
