

#ifndef TWIN_STAFF
#define TWIN_STAFF

#include "actor.hpp"
#include "atlas.hpp"

namespace twin
{
    
    class Fire : public Actor
    {
        public:
        
        Fire(int x,int y,SDL_Texture* texture);
        void update(int ms,std::list<SDL_Event>& events);
    };


    class Player : public Actor
    {
        public:
        
        Atlas* atlas;
        
        bool key[4];
        
        Player(Atlas* atlas);
        
        void update(int ms,std::list<SDL_Event>& events);
        
    };
}


#endif
