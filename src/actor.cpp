

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

Actor::~Actor()
{
}

void Actor::set(SDL_Texture* texture)
{
    this->texture=texture;
    
    uint32_t sink1;
    int sink2;
    
    SDL_QueryTexture(texture,&sink1,&sink2,&rect.w,&rect.h);
    
    //rect.x=0;
    //rect.y=0;
    
    offset.x=rect.w/2;
    offset.y=rect.h/2;
    
}

bool Actor::collision(Actor* actor)
{
    SDL_Rect a,b;
    
    a.x=rect.x-offset.x;
    a.y=rect.y-offset.y;
    a.w=rect.w;
    a.h=rect.h;
    
    b.x=actor->rect.x-actor->offset.x;
    b.y=actor->rect.y-actor->offset.y;
    b.w=actor->rect.w;
    b.h=actor->rect.h;
    
    return SDL_HasIntersection(&a,&b);
}

void Actor::kill()
{
    status = ActorStatus::Dead;
}

void Actor::update(int ms)
{
}

