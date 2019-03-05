

#include "atlas.hpp"

#include <SDL2/SDL_image.h>


using namespace std;
using namespace twin;


Atlas::Atlas(string filename,string name) : Node(name,"atlas")
{
    //this->renderer=Game::get()->get_context();
    SDL_Renderer* renderer;
    
    SDL_Surface* data = IMG_Load(filename);
    this->texture = SDL_CreateTextureFromSurface(renderer,data);
    
    SDL_FreeSurface(data);
}

Atlas::~Atlas()
{
    SDL_DestroyTexture(this->texture);
}

SDL_Texture* Atlas::get_texture()
{
    return this->texture;
}
