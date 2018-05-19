
#include "screen.hpp"
#include "game.hpp"

using namespace twin;
using namespace std;

Screen::Screen(string name)
{
    this->renderer=Game::get()->get_context();
    this->name=name;
    this->child=nullptr;
}

Screen::~Screen()
{
}

void Screen::update(int ms)
{
    // add those actor waiting to enter
    for (Actor* actor: incoming) {
        actors.push_back(actor);
    }
    
    incoming.clear();
    
    // clear draw candidates
    to_draw.clear();
    
    // update actor status and get rid off dead ones
    list<Actor*> tmp;
    
    for (Actor* actor: actors) {
        
        if (actor->status!=ActorStatus::Dead) {
            tmp.push_back(actor);
            
            if (actor->status==ActorStatus::Run) {
                actor->update(ms);
                to_draw.push_back(actor);
            }
        }
    }
    
    actors=tmp;
}


void Screen::draw()
{
    // lambda compare function
    auto comp = []( Actor* a, Actor* b) { return a->z < b->z; };
    
    // z sort
    std::stable_sort(to_draw.begin(),to_draw.end(),comp);
    
    for (Actor* actor:to_draw) {
        SDL_Rect rect;
                
        rect.x=actor->rect.x-actor->offset.x;
        rect.y=actor->rect.y-actor->offset.y;
        rect.w=actor->rect.w;
        rect.h=actor->rect.h;
        
        SDL_RenderCopy(renderer,
            actor->texture,
            nullptr,
            &rect);
    }
}

void Screen::add(Actor* actor)
{
    incoming.push_front(actor);
}

Actor* Screen::first(std::string name)
{
    Actor* tmp=nullptr;
    
    for (Actor* actor:actors) {
        if (actor->name==name) {
            tmp=actor;
            break;
        }
    }
    
    return tmp;
}

void Screen::kill_all()
{
    // TODO: rethink this approach
    
    for (Actor* actor:actors) {
        actor->kill();
    }
}

