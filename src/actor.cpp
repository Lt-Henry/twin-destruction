

#include "actor.hpp"


using namespace std;
using namespace twin;


Actor::Actor()
{
    this->texture=nullptr;
    
    
    rect.x=0;
    rect.y=0;
    rect.w=0;
    rect.h=0;
    
    offset.x=0;
    offset.y=0;
    
    z=0;
    
    status = ActorStatus::Sleep;
}

void Actor::set(SDL_Texture* texture)
{
    this->texture=texture;
    
    uint32_t sink1;
    int sink2;
    
    SDL_QueryTexture(texture,&sink1,&sink2,&rect.w,&rect.h);
    
    rect.x=0;
    rect.y=0;
    
    offset.x=rect.w/2;
    offset.y=rect.h/2;
    
}

Actor::~Actor()
{
}

void Actor::update(int ms)
{
}

