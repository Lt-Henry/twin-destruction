

#include "atlas.hpp"

using namespace std;
using namespace twin;

map<string,Atlas*> Atlas::atlas;

Atlas::Atlas(SDL_Renderer* renderer, const char* filename)
{
    this->renderer=renderer;
    this->data=IMG_Load(filename);
}


Atlas::~Atlas()
{
    SDL_FreeSurface(data);
}


SDL_Texture* Atlas::get(int x,int y,int w,int h)
{
    SDL_Surface* surface;
    SDL_Texture* texture;
    
    surface = SDL_CreateRGBSurface(0, w, h, 32, 
    0x000000ff,
    0x0000ff00,
    0x00ff0000,
    0xff000000);
    
    SDL_Rect source;
    
    source.x=w*x;
    source.y=h*y;
    source.w=w;
    source.h=h;
    
    SDL_BlitSurface(this->data,&source,surface,nullptr);
    
    texture=SDL_CreateTextureFromSurface(this->renderer,surface);
    SDL_FreeSurface(surface);
    
    
    return texture;
}

