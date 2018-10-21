
#include "name.hpp"

#include <iostream>

//#include "game.hpp"

using namespace twin;
using namespace std;

int main(int argc,char* argv[])
{

    clog<<"Twin destruction"<<endl;
    clog<<"Copyright: Enrique Medina 2018"<<endl;

    Name n1("twin");
    Name n2("destruction");
    Name n3=n1;
    clog<<n3.get_name()<<endl;
    clog<<(n1==n2)<<endl;
    clog<<(n2!=n3)<<endl;
    //Game game(argc,argv);
    
    //game.run();

    return 0;
}
