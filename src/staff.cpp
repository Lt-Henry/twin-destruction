

#include "staff.hpp"
#include "game.hpp"
#include "atlas.hpp"

#include <iostream>

using namespace std;
using namespace twin;

Fire::Fire(int x,int y)
{
    texture = Atlas::atlas["sprites"]->get(0,2,32,32);
    set(texture);
    
    rect.x=x;
    rect.y=y;
    
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
    
    hot=0;
    
}

void Player::update(int ms)
{

    hot+=ms;


    Fire* fire;
    
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
    
    if (keyboard[SDL_SCANCODE_F] and hot>100) {
        fire = new Fire(rect.x,
            rect.y-32);
        hot=0;
        children.push_front(fire);
    }
    
    
}

