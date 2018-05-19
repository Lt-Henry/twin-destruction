
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
        
        //std::vector<SDL_Texture*> tileset;
        //uint16_t* tiles;
    
        public:
        
        static Game* get();
        
        SDL_Renderer* get_context();
        
        Game(int argc,char* argv[]);
        ~Game();
        
        void run();
        
        void update(int ms);
        
        void show(Screen* screen);
        
        
    };
}

#endif
