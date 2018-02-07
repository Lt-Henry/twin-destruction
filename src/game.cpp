

#include "game.hpp"
#include "atlas.hpp"
#include "staff.hpp"

#include <iostream>
#include <cmath>

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

    Atlas::atlas["sprites"]=new Atlas(renderer,"sprites.png");
    Atlas::atlas["tiles"]=new Atlas(renderer,"tiles.png");
    
    tiles= new uint16_t[14*10];
    
    for (int n=0;n<(14*10);n++) {
        tiles[n] = rand() % 3;
    }
    
    for (int n=0;n<5;n++) {
        tileset.push_back(Atlas::atlas["tiles"]->get(n,0,64,64));
    }
    
    add(new Player(400,400));
    


    clog<<"Main loop"<<endl;
    
    uint32_t tick = 0;
    uint32_t tack = SDL_GetTicks();
    uint32_t delta = 1;
    uint32_t fpst = SDL_GetTicks();
    
    int frames = 0;

    while (!quit_request) {
        tick = SDL_GetTicks();
        
        SDL_Event event;
        
        while(SDL_PollEvent(&event)) {
            
            switch (event.type) {
                case SDL_QUIT:
                    clog<<"Quit requested"<<endl;
                    quit_request=true;
                break;
            }
        }
        
        SDL_RenderClear(renderer);
        
        draw_background();
        
        update(delta);
        SDL_RenderPresent(renderer);
        
        tack = SDL_GetTicks();
        delta = tack-tick;
        
        int delay = (delta<16) ? 16-delta : 0;
        SDL_Delay(delay);
        delta+=delay;
        
        frames++;
        
        if ((SDL_GetTicks() - fpst)>1000) {
            clog<<"fps: "<<frames<<endl;
            frames=0;
            fpst = SDL_GetTicks();
        }
    }
}

void Game::add(Actor* actor)
{
    actors.push_front(actor);
}


void Game::update(int ms)
{
    list<Actor*> tmp;
    
    for (Actor* actor: actors) {
        
        if (actor->status!=ActorStatus::Dead) {
            tmp.push_front(actor);
            
            if (actor->status==ActorStatus::Run) {
                actor->update(ms);
                
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

void Game::draw_background()
{
    for (int i=0;i<14;i++) {
        for (int j=0;j<10;j++) {
            SDL_Rect rect;
            
            rect.x=i*64;
            rect.y=j*64;
            rect.w=64;
            rect.h=64;
            
            SDL_RenderCopy(renderer,
                tileset[tiles[i+j*14]],
                nullptr,
                &rect);
        }
    }
}
