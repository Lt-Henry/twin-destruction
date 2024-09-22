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

Game* Game::instance=nullptr;

Game::Game() : Node("game","game")
{
    clog<<"Creating game core..."<<endl;
    quit_request=false;
    drawops=nullptr;
    
    SDL_Init(SDL_INIT_EVERYTHING);
    
    window = SDL_CreateWindow("Twin Destruction",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        0,0, SDL_WINDOW_FULLSCREEN_DESKTOP);
        
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    //Set game as root
    Node::set_root(this);
}

Game* Game::get()
{
    return Game::instance;
}

Game* Game::create(int argc,char* argv[])
{
    if (!Game::instance) {
        Game::instance=new Game();
    }
    
    return Game::instance;
}

static void insert_drawop(DrawOp* q,DrawOp* t)
{
    if (t->z<q->z) {
        if (q->left==nullptr) {
            q->left=t;
        }
        else {
            insert_drawop(q->left,t);
        }
    }
    else {
        if (q->right==nullptr) {
            q->right=t;
        }
        else {
            insert_drawop(q->right,t);
        }
    }
}

static void delete_drawop(DrawOp* q)
{
    if (q) {
        if (q->left) {
            delete_drawop(q->left);
        }
        if (q->right) {
            delete_drawop(q->right);
        }
        
        delete q;
    }
}

void Game::draw(Sprite* sprite,Point position,int z)
{
    DrawOp* op = new DrawOp(position.x(),position.y(),z,sprite);
    
    if(!Game::instance->drawops) {
        Game::instance->drawops=op;
    }
    else {
        insert_drawop(Game::instance->drawops,op);
    }
}

void Game::draw(Sprite* sprite,Point position,Point center,int z)
{
    draw(sprite,position-center,z);
}

Point Game::screen_size()
{
    int w,h;
    SDL_GetWindowSize(Game::get()->window,&w,&h);

    return Point(w,h);
}

Point Game::screen_center()
{
    Point p = Game::screen_size();
    return Point(p.x()/2,p.y()/2);
}

Game::~Game()
{
    Game::instance=nullptr;
}

void Game::run()
{
    clog<<"Main loop"<<endl;
    
    uint32_t tick = 0;
    uint32_t tack = SDL_GetTicks();
    uint32_t delta = 1;
    uint32_t fpst = SDL_GetTicks();
    
    int frames = 0;
    
    //Sprite* logo=Node::get<Sprite>({"sprites.logo"});

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
        
        update(delta);
        
        render();
        
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

void Game::populate(Actor* actor)
{
    Name actor_t("actor");
    
    to_update.push_back(actor);
    
    for (Node* child : actor->children) {
        if (child->type==actor_t) {
            populate((Actor*)child);
        }
        
    }
}

void Game::update(int ms)
{
   if (actor) {
       
       to_update.clear();
       populate(actor);
        //update(actor,ms);
   }
   
   for (Actor* q : to_update) {
       q->update(ms);
   }
}

static void draw_drawop(SDL_Renderer* renderer,DrawOp* q)
{
    if (q) {
        
        if (q->left) {
            draw_drawop(renderer,q->left);
        }
        
        q->sprite->draw(renderer,q->x,q->y);
        
        if (q->right) {
            draw_drawop(renderer,q->right);
        }
    }
}

void Game::render()
{
    SDL_RenderClear(renderer);
    
    draw_drawop(renderer,drawops);
    delete_drawop(drawops);
    drawops=nullptr;
    
    SDL_RenderPresent(renderer);
}

void Game::show(Actor* actor)
{
    this->actor=actor;
}

void Game::show(Path actor)
{
    Node* q=Node::root()->get_path(actor);
    
    if (q->type=="actor") {
        this->actor=static_cast<Actor*>(q);
    }
}

Actor* Game::top()
{
    return actor;
}

void Game::quit()
{
    quit_request=true;
}
