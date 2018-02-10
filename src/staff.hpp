

#ifndef TWIN_STAFF
#define TWIN_STAFF

#include "actor.hpp"
#include "atlas.hpp"

namespace twin
{

    class Smoke: public Actor
    {
        public:
        
        int live;
        int n;
        
        Smoke(int x,int y);
        
        void update(int ms);
    };

    class Missile: public Actor
    {
        public:
        
        float a;
        float v;
        float dist;
        
        Missile (int x,int y);
        void update(int ms);
    };
    
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
        int reload;
        int side;
        
        Player(int x,int y);
        void update(int ms);
        
    };
}


#endif
