
#include <iostream>

#include "game.hpp"

using namespace std;
using namespace twin;

int main(int argc,char* argv[])
{

    clog<<"Twin destruction"<<endl;
    clog<<"Copyright: Enrique Medina 2018"<<endl;


    Game game(argc,argv);
    
    game.run();

    return 0;
}
