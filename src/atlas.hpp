
#ifndef TWIN_ATLAS
#define TWIN_ATLAS

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace twin
{
    class Atlas
    {
    
        private:
        
        SDL_Surface* data;
        SDL_Renderer* renderer;
        
        
        public:
        
        Atlas(SDL_Renderer* renderer,const char* filename);
        ~Atlas();
        
        SDL_Texture* get(int x,int y,int w,int h);
        
    };
}

#endif
