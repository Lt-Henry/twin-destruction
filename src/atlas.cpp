

#include "atlas.hpp"

#include <fstream>
#include <vector>

using namespace std;
using namespace twin;

vector<string> tokenizer(string line)
{
    vector<string> tokens;
    
    bool knee=false;
    string tmp;

    for (char c : line) {

        if (c==' ') {
            if (knee==true) {
                tokens.push_back(tmp);
                knee=false;
                tmp="";
            }
        }
        else {
            tmp=tmp+c;
            knee=true;
        }
    }

    if (tmp!="") {
        tokens.push_back(tmp);
    }
    
    return tokens;
}


Atlas* Atlas::atlas=nullptr;

Atlas::Atlas()
{
    this->renderer=Game::get()->get_context();
    
    
    //this->data=IMG_Load(filename);
}

Atlas* Atlas::get()
{
    return Atlas::atlas;
}

Atlas::~Atlas()
{
    //SDL_FreeSurface(data);
}

void Atlas::load(char* filename)
{
    fstream file;
    
    file.open(filename,fstream::in);
    string line;
    vector<string> tokens;
    bool is_loaded=false;
    
    while(!file.eof()) {
        
        getline(file,line);
        
        tokens=tokenizer(line);
        
        if (tokens.size()<2) {
            continue;
        }
        
        if (tokens[0]=="filename") {
        }
    }
    
    file.close();

}

SDL_Texture* Atlas::get(int x,int y,int w,int h)
{
    SDL_Surface* surface;
    SDL_Texture* texture;
    
    surface = SDL_CreateRGBSurface(0, w, h, 32, 
    0x000000ff,
    0x0000ff00,
    0x00ff0000,
    0xff000000);
    
    SDL_Rect source;
    
    source.x=w*x;
    source.y=h*y;
    source.w=w;
    source.h=h;
    
    SDL_BlitSurface(this->data,&source,surface,nullptr);
    
    texture=SDL_CreateTextureFromSurface(this->renderer,surface);
    SDL_FreeSurface(surface);
    
    
    return texture;
}

