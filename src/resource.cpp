
#include "resource.hpp"
#include "utils.hpp"

#include <iostream>
#include <fstream>

using namespace twin;
using namespace std;



void Resource::load(const char* filename)
{
    fstream file;
    
    file.open(filename,fstream::in);
    string line;
    vector<string> tokens;
    vector<string> stack;
    
    
    while(!file.eof()) {
        
        getline(file,line);
        
        tokens=split(line);
        
        if (tokens.size()==0) {
            continue;
        }
        
        //clog<<tokens[0]<<endl;
        
        if (tokens[0]=="resource") {
            stack.push_back(tokens[0]);
            clog<<"resource "<<tokens[1]<<endl;
        }
        
        if (tokens[0]=="atlas") {
            stack.push_back(tokens[0]);
            clog<<"atlas "<<tokens[1]<<endl;
        }
        
        if (tokens[0]=="end") {
            if (stack.size()>0) {
                stack.pop_back();
            }
        }
        
    }
    
}
