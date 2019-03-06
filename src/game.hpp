
#ifndef TWIN_GAME
#define TWIN_GAME

#include "screen.hpp"
#include "actor.hpp"

#include <SDL2/SDL.h>

#include <list>
#include <vector>


namespace twin
{
    class Game
    {
    
        private:
        
        bool quit_request;
        
        SDL_Window* window;
        SDL_Renderer* renderer;
        
        Screen* screen;
        
        static Game* game;
        
        public:
        
        static Game* get();
        
        SDL_Renderer* get_context();
        
        Game(int argc,char* argv[]);
        virtual ~Game();
        
        void run();
        
        void update(int ms);
        
        void show(Screen* screen);
        
        
    };
}

#endif
