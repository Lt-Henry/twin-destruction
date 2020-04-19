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

#include "menu.hpp"
#include "atlas.hpp"
#include "game.hpp"

#include <SDL2/SDL.h>

using namespace twin;
using namespace std;

Pointer::Pointer() : Actor("pointer",Point(0,0))
{
    sprite = Node::get<Sprite>({"sprites.pointer"});
    SDL_ShowCursor(0);
    
    box = sprite->box();
}

void Pointer::update(int ms)
{
    int mx,my;
    SDL_GetMouseState(&mx,&my);
    position[0]=mx;
    position[1]=my;
    
    Game::draw(sprite,position,100);
}

Button::Button() : Actor("button",Point(0,0))
{
    normal = Node::get<Sprite>({"sprites.button_normal"});
    hover = Node::get<Sprite>({"sprites.button_hover"});
    
    sprite = normal;
    
    box = sprite->box();
}

void Button::update(int ms)
{
    static Name pointer_name("pointer");
    Actor* pointer = static_cast<Actor*>(parent->first(pointer_name));
    
    if (collision(pointer,0)) {
        sprite = hover;
    }
    else {
        sprite = normal;
    }
    
    Game::draw(sprite,position,1);
}

Menu::Menu() : Actor("menu",Point(0,0))
{
    Atlas* atlas = new Atlas("backgrounds.png","backgrounds");
    atlas->create_sprite(1280,720,0,0,"menu");
    Node::root()->add(atlas);
    
    atlas = new Atlas("sprites.png","sprites");
    atlas->create_sprite(192,64,0,4,"logo");
    atlas->create_sprite(32,32,6,8,"pointer");
    
    atlas->create_sprite(64,64,0,5,"button_normal");
    atlas->create_sprite(64,64,1,5,"button_hover");
    
    Node::root()->add(atlas);
    
    sprite = Node::get<Sprite>({"backgrounds.menu"});
    
    add(new Pointer());
    
    Button* button = new Button();
    button->position = sprite->center();
    
    add(button);
}

Menu::~Menu()
{
}

void Menu::update(int ms)
{
    Game::draw(sprite,position,0);
}
