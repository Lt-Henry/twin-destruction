

#include "staff.hpp"
#include "game.hpp"
#include "atlas.hpp"

#include <iostream>

using namespace std;
using namespace twin;

Rock::Rock(int x,int y)
{
    texture = Atlas::atlas["sprites"]->get(0,2,64,64);
    set(texture);
    
    rect.x=x;
    rect.y=y;
    
    z=10;
    
    status = ActorStatus::Run;
}

void Rock::update(int ms)
{
    rect.y+=3;
    
    if (rect.y>600) {
        status = ActorStatus::Dead;
    }
}

Fire::Fire(int x,int y)
{
    texture = Atlas::atlas["sprites"]->get(0,2,32,32);
    set(texture);
    
    rect.x=x;
    rect.y=y;
    
    z=200;
    
    status = ActorStatus::Run;
}

void Fire::update(int ms)
{
    rect.y-=10;
    
    if (rect.y<0) {
        status = ActorStatus::Dead;
    }
}

Player::Player(int x,int y)
{
    
    
    texture = Atlas::atlas["sprites"]->get(0,0,64,64);
    set(texture);
    rect.x=x;
    rect.y=y;
    
    status = ActorStatus::Run;
    
    z=32767;
    
    hot=0;
    
    shadow = new Actor();
    shadow->set(Atlas::atlas["sprites"]->get(1,0,64,64));
    shadow->z=z-1;
    shadow->status = ActorStatus::Run;
    
    Game::get()->add(shadow);
}

void Player::update(int ms)
{

    hot+=ms;


    
    const uint8_t* keyboard = SDL_GetKeyboardState(nullptr);
    
    if (keyboard[SDL_SCANCODE_LEFT]) {
        rect.x--;
    }
    
    if (keyboard[SDL_SCANCODE_RIGHT]) {
        rect.x++;
    }
    
    if (keyboard[SDL_SCANCODE_UP]) {
        rect.y--;
    }
    
    if (keyboard[SDL_SCANCODE_DOWN]) {
        rect.y++;
    }
    
    if (keyboard[SDL_SCANCODE_R]) {
        Rock* rock = new Rock(rand()%800,0);
        Game::get()->add(rock);
    }
    
    if (keyboard[SDL_SCANCODE_F] and hot>100) {
        Fire* fire = new Fire(rect.x,
                    rect.y-32);
        hot=0;
        
        Game::get()->add(fire);
    }
    
    shadow->rect.x=rect.x-16;
    shadow->rect.y=rect.y-16;
    
}

