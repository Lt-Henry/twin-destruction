
#include "screen.hpp"


using namespace twin;
using namespace std;

Screen::Screen()
{
}

Screen::~Screen()
{
}

void Screen::update(int ms)
{
}


void Screen::draw()
{
}

void Screen::add(Actor* actor)
{
    incoming.push_front(actor);
}

Actor* Screen::first(std::string name)
{
    Actor* tmp=nullptr;
    
    for (Actor* actor:actors) {
        if (actor->name==name) {
            tmp=actor;
            break;
        }
    }
    
    return tmp;
}

void Screen::kill_all()
{
}

void Screen::pause()
{
}

void Screen::resume()
{
}
