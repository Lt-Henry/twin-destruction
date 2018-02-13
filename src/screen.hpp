
#ifndef TWIN_SCREEN
#define TWIN_SCREEN

#include <list>

#include "actor.hpp"

namespace twin
{
    class Screen
    {
        private:
        
        std::list<Actor*> actors;
        std::list<Actor*> incoming;
    
        public:
        
        Screen();
        virtual ~Screen();
        
        virtual void update(int ms);
        
        virtual void draw();
        
        void add(Actor* actor);
        Actor* first(std::string name);
        
        void kill_all();
        void pause();
        void resume();
    };
}

#endif
