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

#include "game.hpp"
#include "atlas.hpp"
#include "sprite.hpp"

#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace twin;
using namespace std;

Game::Game(int argc,char * argv[]) : Node("game","game")
{
    clog<<"Creating game core..."<<endl;
    quit_request=false;
    
    Node* root=Node::root();
    
    Node* atlas_node = root->create_path({"resources.atlas"});
    
    SDL_Init(SDL_INIT_EVERYTHING);
    
    window = SDL_CreateWindow("Twin Destruction",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1280,720, SDL_WINDOW_SHOWN);
        
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    //add game node to tree
    root->add(this);
    
    //Load resources
    
    Atlas* atlas;
    
    atlas = new Atlas(renderer,"backgrounds.png","backgrounds");
    atlas_node->add(atlas);
    
    Sprite* sprite;
    
    sprite = new Sprite(atlas,1280,720,0,0,"menu");
    
    
}

Game::~Game()
{
}

void Game::run()
{

    clog<<"Main loop"<<endl;
    
    uint32_t tick = 0;
    uint32_t tack = SDL_GetTicks();
    uint32_t delta = 1;
    uint32_t fpst = SDL_GetTicks();
    
    int frames = 0;
    
    Sprite* background=static_cast<Sprite*>(Node::root()->get_path({"resources.atlas.backgrounds.sprites.menu"}));

    while (!quit_request) {
        tick = SDL_GetTicks();
        
        SDL_Event event;
        
        while(SDL_PollEvent(&event)) {
            
            switch (event.type) {
                case SDL_QUIT:
                    clog<<"Quit requested"<<endl;
                    quit_request=true;
                break;
            }
        }
        
        SDL_RenderClear(renderer);
        
        update(delta);
        
        background->draw(renderer,0,0);
        
        SDL_RenderPresent(renderer);
        
        tack = SDL_GetTicks();
        delta = tack-tick;
        
        int delay = (delta<16) ? 16-delta : 0;
        SDL_Delay(delay);
        delta+=delay;
        
        frames++;
        
        if ((SDL_GetTicks() - fpst)>1000) {
            clog<<"fps: "<<frames<<endl;
            frames=0;
            fpst = SDL_GetTicks();
        }
    }
}

void Game::update(int ms)
{
   
}

