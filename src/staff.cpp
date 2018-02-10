

#include "staff.hpp"
#include "game.hpp"
#include "atlas.hpp"

#include <iostream>

using namespace std;
using namespace twin;

Smoke::Smoke(int x,int y)
{
    texture = Atlas::atlas["sprites"]->get(0,3,32,32);
    set(texture);
    
    rect.x=x;
    rect.y=y;
    
    z=9;
    
    live=0;
    n=0;
    
    status = ActorStatus::Run;
}

void Smoke::update(int ms)
{
    live+=ms;
    
    if (live>100) {
        live=0;
        n++;
        
        if (n==5) {
            status = ActorStatus::Dead;
        }
        else {
            texture = Atlas::atlas["sprites"]->get(n,3,32,32);
            set(texture);
        }
    }
}

Missile::Missile(int x,int y)
{
    texture = Atlas::atlas["sprites"]->get(1,2,32,32);
    set(texture);
    
    rect.x=x;
    rect.y=y;
    
    z=10;
    
    a=10.0f;
    v=0.0f;
    dist=0.0f;
    
    status = ActorStatus::Run;
}

void Missile::update(int ms)
{
    rect.y-=v;
    v=v+a*(ms/1000.0f);
    dist+=v;
    
    if (dist>10.0f) {
        Smoke* smoke = new Smoke(rect.x,rect.y);
        Game::get()->add(smoke);
        dist=0.0f;
    }
    
    if (rect.y<0) {
        status = ActorStatus::Dead;
    }
}

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
    reload=0;
    side=32;
    
    shadow = new Actor();
    shadow->set(Atlas::atlas["sprites"]->get(1,0,64,64));
    shadow->z=z-1;
    shadow->status = ActorStatus::Run;
    
    Game::get()->add(shadow);
}

void Player::update(int ms)
{

    hot+=ms;
    reload+=ms;

    
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
    
    if (keyboard[SDL_SCANCODE_M] and reload>500) {
        Missile* missile = new Missile(rect.x-side,rect.y);
        reload=0;
        side=-side;
        
        Game::get()->add(missile);
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

