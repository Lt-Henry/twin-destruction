
#ifndef TWIN_GAME
#define TWIN_GAME

#include <SDL2/SDL.h>
#include <list>
#include "actor.hpp"

namespace twin
{
    class Game
    {
    
        private:
        
        bool quit_request;
        
        SDL_Window* window;
        SDL_Renderer* renderer;
        
        std::list<Actor*> actors;
        
        static Game* game;
    
        public:
        
        static Game* get_game();
        
        Game(int argc,char* argv[]);
        ~Game();
        
        void run();
        
        void add(Actor* actor);
        void update(int ms,std::list<SDL_Event>& events);
        
    };
}

#endif
