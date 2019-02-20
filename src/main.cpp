
#include "name.hpp"
#include "node.hpp"
#include "resource.hpp"

#include <iostream>

//#include "game.hpp"

using namespace twin;
using namespace std;

void print(Node* q,int depth=0)
{
    for (int n=0;n<depth;n++) {
        cout<<'-';
    }
        
    cout<<q->name.get_name()<<endl;
    
    for (Node* p: q->children) {
        print(p,depth+1);
    }
}

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
    
    Node* root=Node::root();
    
    Node* tmp=new Node("textures");
    root->add(tmp);
    
    Node* qtmp=new Node("backgrounds");
    tmp->add(qtmp);
    
    tmp=new Node("audio");
    root->add(tmp);
    
    print(root);
    
    Resource::load("p1.rsrc");
    //Game game(argc,argv);
    
    //game.run();

    return 0;
}
