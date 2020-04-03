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
        
        Sprite* sprite;
        
        DrawOp* left;
        DrawOp* right;
        
        DrawOp(int x,int y,int z,Sprite* sprite): x(x),y(y),z(z),sprite(sprite)
        {
            left=nullptr;
            right=nullptr;
        }
    };
    
    class Game: public Node
    {
    
        protected:
            
        DrawOp* drawops;
        
        bool quit_request;
        static Game* instance;
        
        Game();
        
        public:
        
        enum Flags: int {
            relative = 1,
            absolute = 2,
            center = 4,
            topleft = 8
        };
        
        SDL_Window* window;
        SDL_Renderer* renderer;
        
        static Game* get();
        static Game* create(int argc,char* argv[]);
        static void draw(Sprite* sprite,Point position,int flags,int z=0);
        
        virtual ~Game();
        
        void run();
        
        void update(int ms);
        
        void render();
    };
}

#endif
