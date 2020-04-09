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

#ifndef TWIN_POINT
#define TWIN_POINT

#include <cmath>

namespace twin
{
    class Point
    {
        public:
        
        double data[2];
        
        Point()
        {
            
        }
        
        Point(double x,double y)
        {
            data[0]=x;
            data[1]=y;
        }
        
        double x()
        {
            return data[0];
        }
        
        double y()
        {
            return data[1];
        }
        
        Point operator+(Point& p)
        {
            return Point(x()+p.x(),y()+p.y());
        }
        
        Point operator-(Point& p)
        {
            return Point(x()-p.x(),y()-p.y());
        }

        double norm()
        {
            return std::sqrt((x()*x()) + (y()*y()));
        }
        
        double operator[](int n)
        {
            n = n & 0x01;
            return data[n];
        }
    };
}
#endif
