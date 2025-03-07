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

Pointer::Pointer() : Actor("pointer",Point(0,0)), buttons(0)
{
    sprite = Node::get<Sprite>("ui.pointer");
    SDL_ShowCursor(0);
    
    box = sprite->box();
}

void Pointer::update(int ms)
{
    int mx,my;
    buttons = SDL_GetMouseState(&mx,&my);
    position[0]=mx;
    position[1]=my;
    
    sprite->draw(position,100);
}

Button::Button(string name) : Actor(name,Point(0,0))
{
    normal = Node::get<Sprite>("assets."+name+"_normal");
    hover = Node::get<Sprite>("assets."+name+"_hover");
    
    sprite = normal;
    
    box = sprite->box();
}

void Button::update(int ms)
{
    static Name pointer_name("pointer");
    Actor* pointer = static_cast<Actor*>(parent->first(pointer_name));
    
    if (collision(pointer,0)) {
        sprite = hover;
        if ( static_cast<Pointer*>(pointer)->buttons & SDL_BUTTON_LMASK ) {
            if (name=="btn_exit") {
                Game::get()->quit();
            }
        }
    }
    else {
        sprite = normal;
    }
    
    sprite->draw(position,1);
}

Menu::Menu() : Actor("menu",Point(0,0))
{

    Atlas* atlas = new Atlas("assets.png","assets");

    atlas->create_sprite(32,32,6,8,"pointer");
    
    atlas->create_sprite(64,64,0,5,"btn_exit_normal");
    atlas->create_sprite(64,64,1,5,"btn_exit_hover");
    atlas->create_sprite(64,64,0,6,"btn_play_normal");
    atlas->create_sprite(64,64,1,6,"btn_play_hover");
    
    atlas->create_sprite(64,64,0,9,"background");

    Node::root()->add(atlas);

    atlas = new Atlas("ui.png","ui");
    atlas->create_sprite(32,32,0,0,"background");
    atlas->create_sprite(32,32,1,0,"pointer");
    Node::root()->add(atlas);

    sprite = Node::get<Sprite>("ui.background");
    
    add(new Pointer());
    
    Button* button = new Button("btn_play");
    button->position = Game::screen_center();
    
    add(button);
    
    button = new Button("btn_exit");
    button->position = Game::screen_center() + Point(0,64);
    
    add(button);
}

Menu::~Menu()
{
}

void Menu::update(int ms)
{
    Point ssize = Game::screen_size();
    int w = sprite->box().bottom_right().x();
    int h = sprite->box().bottom_right().y();

    for (int j=0;j<ssize.y();j+=h) {
        for (int i=0;i<ssize.x();i+=w) {
            //Game::draw(sprite,Point(i,j),0);
            sprite->draw(Point(i,j),0);
        }
    }

}
