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

#ifndef TWIN_GAME
#define TWIN_GAME

#include "node.hpp"
#include "sprite.hpp"
#include "actor.hpp"

#include <SDL2/SDL.h>

#include <list>
#include <vector>

namespace twin
{
    class DrawOp {
        public:
        
        int x;
        int y;
        int z;
        
        SDL_Texture* texture;
        SDL_Rect rect;
        
        DrawOp* left;
        DrawOp* right;
        
        DrawOp(int x,int y,int z,SDL_Texture* texture, SDL_Rect rect): x(x),y(y),z(z),texture(texture), rect(rect)
        {
            left = nullptr;
            right = nullptr;
        }
    };
    
    class Game: public Node
    {
    
        protected:
            
        DrawOp* drawops;
        std::vector<DrawOp> commands;
        
        bool quit_request;
        static Game* instance;
        Actor* actor;
        std::vector<Actor*> to_update;
        
        Game();
        
        void populate(Actor* actor);
        
        public:
        
        SDL_Window* window;
        SDL_Renderer* renderer;
        
        static Game* get();
        static Game* create(int argc,char* argv[]);
        static void draw(SDL_Texture* texture, SDL_Rect rect,Point position,int z=0);
        static void draw(SDL_Texture* texture, SDL_Rect rect,Point position, Point center, int z=0);

        static Point screen_size();
        static Point screen_center();
        
        virtual ~Game();
        
        void run();
        
        void update(int ms);
        
        void render();
        
        void show(Actor* actor);
        
        void show(Path actor);
        
        Actor* top();
        
        void quit();
    };
}

#endif
