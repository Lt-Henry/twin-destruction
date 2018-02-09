
#ifndef TWIN_ACTOR
#define TWIN_ACTOR

#include <SDL2/SDL.h>

#include <list>
#include <string>

namespace twin
{

    enum class ActorStatus {
        Run,
        Sleep,
        Dead
    };

    class Actor
    {
        public:
        
        ActorStatus status;
        
        SDL_Rect rect;
        SDL_Point offset;
        int z;
        
        SDL_Texture* texture;
        
        std::string name;
        
        
        Actor();
        virtual ~Actor();
        
        void set(SDL_Texture* texture);
        
        virtual void update(int ms);
        
    
    };
}


#endif
