/*
 * Copyright (C) 2020 Twin destruction
 *
 * Author:
 *  Enrique Medina Gremaldos <quiqueiii@gmail.com>
 *
 * Source:
 *  https://github.com/Lt-Henry/twin-destruction
 *
 * This file is a part of Twin destruction
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 */
 
#include "name.hpp"
#include "node.hpp"

#include <iostream>

//#include "game.hpp"

using namespace twin;
using namespace std;

void print(Node* q,int depth=0)
{
    for (int n=0;n<depth;n++) {
        cout<<'-';
    }
        
    cout<<q->name.get_name()<<":"<<q->type.get_name()<<endl;
    
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
    
    root->create_path(Path("resources.atlas"));
    root->create_path(Path("resources.audio"));
    root->create_path(Path("game.actors"));

    print(root);
    
    //game.run();

    return 0;
}
