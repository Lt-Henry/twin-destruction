

#ifndef TWIN_STAFF
#define TWIN_STAFF

#include "actor.hpp"
#include "atlas.hpp"

namespace twin
{
    
    class Fire : public Actor
    {
        public:
        
        Fire(int x,int y);
        void update(int ms);
    };


    class Player : public Actor
    {
        public:
        
        int hot;
        
        Player(int x,int y);
        void update(int ms);
        
    };
}


#endif
