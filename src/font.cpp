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
 
#include "font.hpp"
#include "game.hpp"

#include <codecvt>
#include <string>
#include <locale>
#include <iostream>

using namespace twin;
using namespace std;

Font::Font(string filename, int psize, string name) : Node(name,"font")
{

    TTF_Init();
    
    font = TTF_OpenFont(filename.c_str(),psize);
    if (font) {
        clog<<"Font loaded"<<endl;
    }

}

Font::~Font()
{
    TTF_Quit();
}

Box Font::draw(string text, Point position, int z)
{
    std::u16string text16 = std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t>{}.from_bytes(text);

    Point cr = position;
    Box bbox(position,position);

    for (char16_t c : text16) {
        if (textures.find(c) == textures.end()) {
            update_glyph(c);
        }

        SDL_Texture* texture = textures[c];
        SDL_Rect srcrect {0};
        /*
        int minx,maxx,miny,maxy;
        int advance;
        TTF_GlyphMetrics(font,c,&minx,&maxx,&miny,&maxy,&advance);
        */
        int tw,th;
        SDL_QueryTexture(texture,nullptr,nullptr,&tw,&th);
        srcrect.w = tw;
        srcrect.h = th;
        Game::draw(texture,srcrect,cr,z);

        cr = cr + Point(tw,0);
        bbox.push(Point(tw,th));
    }

    return bbox;
}

void Font::update_glyph(char16_t code)
{
    clog<<"Uploading glyph for "<<code<<endl;

    SDL_Surface* surface = TTF_RenderGlyph_Blended(font,code,{0xff,0xff,0xff,0xff});
    SDL_Renderer* renderer = Game::get()->renderer;

    textures[code] = SDL_CreateTextureFromSurface(renderer,surface);

    SDL_FreeSurface(surface);
}
