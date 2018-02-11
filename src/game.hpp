
#ifndef TWIN_GAME
#define TWIN_GAME

#include <SDL2/SDL.h>
#include <list>
#include <vector>
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
        std::list<Actor*> incoming;
        
        static Game* game;
        
        std::vector<SDL_Texture*> tileset;
        uint16_t* tiles;
    
        public:
        
        static Game* get();
        
        Game(int argc,char* argv[]);
        ~Game();
        
        void run();
        
        void add(Actor* actor);
        void update(int ms);
        void draw_background();
        
        Actor* first(std::string name);
        
    };
}

#endif
