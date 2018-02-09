

#ifndef TWIN_STAFF
#define TWIN_STAFF

#include "actor.hpp"
#include "atlas.hpp"

namespace twin
{
    class Rock: public Actor
    {
        public:
        
        Rock(int x,int y);
        void update(int ms);
        
    };
    
    class Fire : public Actor
    {
        public:
        
        Fire(int x,int y);
        void update(int ms);
    };


    class Player : public Actor
    {
        public:
        
        Actor* shadow;
        
        int hot;
        
        Player(int x,int y);
        void update(int ms);
        
    };
}


#endif
