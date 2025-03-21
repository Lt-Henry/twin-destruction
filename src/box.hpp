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

#ifndef TWIN_BOX
#define TWIN_BOX

#include "point.hpp"

namespace twin
{
    class Box
    {
        public:
        
        Point data[2];
        
        Box()
        {
        }
        
        Box (Point top_left,Point bottom_right)
        {
            data[0]=top_left;
            data[1]=bottom_right;
        }
        
        Box (Point top_left, double width,double height)
        {
            data[0]=top_left;
            data[1]=top_left + Point(width,height);
        }
        
        Point top_left()
        {
            return data[0];
        }
        
        Point top_right()
        {
            return Point(data[1].x(),data[0].y());
        }
        
        Point bottom_left()
        {
            return Point(data[0].x(),data[1].y());
        }

        Point bottom_right()
        {
            return data[1];
        }

        int width()
        {
            return data[1].x() - data[0].x();
        }

        int height()
        {
            return data[1].y() - data[0].y();
        }

        bool inside (Point point)
        {
            if (point[0] >= data[0][0] and
                point[0] <= data[1][0] and
                point[1] >= data[0][1] and
                    point[1] <= data[1][1]) {
                return true;
            }
            
            return false;
        }
        
        bool inside (Box box)
        {
            if (inside(box.top_left()) or
                inside(box.top_right()) or
                inside(box.bottom_left()) or
                inside(box.bottom_right())) {
                
                return true;
            }
            
            return false;
        }
        
        void push(Point p)
        {
            for (int n=0;n<2;n++) {
                if (p[n] < data[0][n]) {
                    data[0][n] = p[n];
                }

                if (p[n] > data[1][n]) {
                    data[1][n] = p[n];
                }
            }
        }

        Point& operator[](int n)
        {
            n = n & 0x01;
            return data[n];
        }
        
        Box operator + (Point p)
        {
            Box b;
            
            b.data[0] = data[0] + p;
            b.data[1] = data[1] + p;
            
            return b;
        }
    };
}

#endif
