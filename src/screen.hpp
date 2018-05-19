
#ifndef TWIN_SCREEN
#define TWIN_SCREEN

#include "actor.hpp"

#include <SDL2/SDL.h>

#include <list>
#include <vector>
#include <string>

namespace twin
{
    class Screen
    {
        protected:
        
        std::list<Actor*> actors;
        std::list<Actor*> incoming;
        std::vector<Actor*> to_draw;
        
        SDL_Renderer* renderer;
        
        std::string name;
        
        Screen* child;
        
        public:
        
        Screen(std::string name);
        virtual ~Screen();
        
        virtual void update(int ms);
        
        virtual void draw();
        
        void add(Actor* actor);
        Actor* first(std::string name);
        
        void kill_all();
        
        void push(Screen* screen);
        void pop();
    };
}

#endif
