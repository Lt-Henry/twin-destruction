
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
        
        public:
        
        //HACK HACK HACK
        static std::map<std::string,Atlas*> atlas;
        
        Atlas(const char* filename);
        ~Atlas();
        
        SDL_Texture* get(std::string name);
        
    };
}

#endif
