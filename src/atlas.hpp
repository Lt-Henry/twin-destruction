
#ifndef TWIN_ATLAS
#define TWIN_ATLAS

#include "node.hpp"

#include <SDL2/SDL.h>


#include <map>
#include <string>

namespace twin
{
    class Atlas : public Node
    {
        private:
        
        SDL_Texture* texture;
        
        public:

        Atlas(std::string filename, std::string name);
        virtual ~Atlas();
        
        SDL_Texture* get_texture();
        
    };
}

#endif
