

#include "staff.hpp"
#include "game.hpp"

#include <iostream>

using namespace std;
using namespace twin;

Fire::Fire(int x,int y,SDL_Texture* texture)
{
    set(texture);
    
    rect.x=x;
    rect.y=y;
    
    status = ActorStatus::Run;
}

void Fire::update(int ms,list<SDL_Event>& events)
{
    rect.y-=10;
    
    if (rect.y<0) {
        status = ActorStatus::Dead;
        clog<<"miss!"<<endl;
    }
}

Player::Player(Atlas* atlas)
{
    this->atlas=atlas;
    
    texture = atlas->get(0,0,64,64);
    set(texture);
    rect.x=400;
    rect.y=400;
    
    status = ActorStatus::Run;
    
    key[0]=false;
    key[1]=false;
    key[2]=false;
    key[3]=false;
}

void Player::update(int ms,list<SDL_Event>& events)
{

    Fire* fire;

    for (SDL_Event& event : events) {
        switch (event.type) {
        
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT:
                        key[0]=true;
                    break;
                    case SDLK_RIGHT:
                        key[1]=true;
                    break;
                    case SDLK_UP:
                        key[2]=true;
                    break;
                    case SDLK_DOWN:
                        key[3]=true;
                    break;
                    
                    case SDLK_f:
                    
                    clog<<"pem"<<endl;
                    fire = new Fire(rect.x,
                        rect.y-32,
                        atlas->get(0,2,32,32));
                    
                    children.push_front(fire);
                    
                    
                    break;
                }
                
            break;
            
            case SDL_KEYUP:
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT:
                        key[0]=false;
                    break;
                    case SDLK_RIGHT:
                        key[1]=false;
                    break;
                    case SDLK_UP:
                        key[2]=false;
                    break;
                    case SDLK_DOWN:
                        key[3]=false;
                    break;
                }
            break;
        }
    }
    
    
    
    if (key[0]) {
        rect.x--;
    }
    
    if (key[1]) {
        rect.x++;
    }

    if (key[2]) {
        rect.y--;
    }
    
    if (key[3]) {
        rect.y++;
    }


    
    
}

