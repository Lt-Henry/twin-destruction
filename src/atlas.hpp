
#ifndef TWIN_ATLAS
#define TWIN_ATLAS

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <map>
#include <string>

namespace twin
{
    class Atlas
    {
    
        private:
        
        std::map<std::string,SDL_Texture*> textures;
        
        static Atlas* atlas;
        
        Atlas();
        
        public:
        
        static Atlas* get();
        
        ~Atlas();
        
        void load(char* filename);
        
        SDL_Texture* get(std::string name);
        
    };
}

#endif
