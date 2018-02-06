

#include "game.hpp"
#include "atlas.hpp"
#include "staff.hpp"

#include <iostream>

using namespace std;
using namespace twin;

Game* Game::game = nullptr;

Game* Game::get_game()
{
    return Game::game;
}

Game::Game(int argc,char * argv[])
{
    clog<<"Creating game core..."<<endl;
    quit_request=false;
    
    SDL_Init(SDL_INIT_EVERYTHING);
    
    window = SDL_CreateWindow("Twin Destruction",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,600, SDL_WINDOW_SHOWN);
        
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    Game::game=this;
}

Game::~Game()
{
}

void Game::run()
{

    Atlas atlas(renderer,"sprites.png");
    
    add(new Player(&atlas));
    

    list<SDL_Event> events;

    clog<<"Main loop"<<endl;

    while (!quit_request) {
    
        events.clear();
        
        SDL_Event event;
        
        while(SDL_PollEvent(&event)) {
            events.push_front(event);
            
            switch (event.type) {
                case SDL_QUIT:
                    clog<<"Quit requested"<<endl;
                    quit_request=true;
                break;
            }
        }
        
        SDL_RenderClear(renderer);
        
        update(15,events);
        SDL_RenderPresent(renderer);
        SDL_Delay(15);
    }
}

void Game::add(Actor* actor)
{
    actors.push_front(actor);
}


void Game::update(int ms,list<SDL_Event>& events)
{
    list<Actor*> tmp;
    
    for (Actor* actor: actors) {
        
        if (actor->status!=ActorStatus::Dead) {
            tmp.push_front(actor);
            
            if (actor->status==ActorStatus::Run) {
                actor->update(ms,events);
                
                for (Actor* child: actor->children) {
                    tmp.push_front(child);
                }
                actor->children.clear();
                
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
    }
    
    actors=tmp;
}
