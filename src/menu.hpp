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
 
#ifndef TWIN_MENU
#define TWIN_MENU

#include "node.hpp"
#include "actor.hpp"

namespace twin
{
    class Pointer: public Actor
    {
        public:
        
        Pointer();
        
        void update(int ms) override;
    };
    
    class Menu : public Actor
    {
        public:
        
        Menu();
        ~Menu();
        
        void update(int ms) override;
    };
}

#endif
