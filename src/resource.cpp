
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
    
    
    while(!file.eof()) {
        
        getline(file,line);
        
        tokens=split(line);
        
        if (tokens.size()==0) {
            continue;
        }
        
        clog<<tokens[0]<<endl;
        
    }
    
}
