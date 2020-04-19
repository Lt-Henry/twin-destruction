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
 
#include "sprite.hpp"

using namespace twin;
using namespace std;

Sprite::Sprite(SDL_Texture* texture,int w,int h,int c,int r,string name) : Node(name,"sprite")
{
    this->texture=texture;
    srcrect.w=w;
    srcrect.h=h;
    srcrect.x=w*c;
    srcrect.y=h*r;
    
}

void Sprite::draw(SDL_Renderer* renderer,int x,int y)
{
    SDL_Rect dstrect;
    
    dstrect.w=srcrect.w;
    dstrect.h=srcrect.h;
    
    dstrect.x=x;
    dstrect.y=y;
    
    SDL_RenderCopy(renderer,texture,&srcrect,&dstrect);
}

Point Sprite::center()
{
    return Point(srcrect.w/2,srcrect.h/2);
}

Box Sprite::box()
{
    return Box(Point(0,0),Point(srcrect.w,srcrect.h));
}
