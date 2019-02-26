
#include "resource.hpp"
#include "utils.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace twin;
using namespace std;



Resource::Resource(const char* filename) : Node("",nullptr)
{
    
    type=Name("Resource");
    
    Node* current=this;
    
    fstream file;
    
    file.open(filename,fstream::in);
    string line;
    vector<string> tokens;
    vector<string> stack;
    vector<string> next ;
    map<string,vector<string> > follow;
    
    stack.push_back("root");
    follow["root"]={"resource"};
    follow["resource"]={"end","atlas","dir"};
    follow["atlas"]={"end","size","tile","dir"};
    
    next=follow[stack.back()];
    
    while(!file.eof()) {
        
        getline(file,line);
        
        tokens=split(line);
        
        if (tokens.size()==0) {
            continue;
        }
        
        // line comment
        if (tokens[0]=="#") {
            continue;
        }
        
        bool unexpected=true;
        
        for (string& nx : next) {
            if (tokens[0]==nx) {
                unexpected=false;
                break;
            }
        }
        
        if (unexpected) {
            cerr<<"Error, expecting: ";
            for (string& nx:next) {
                cerr<<nx<<" ";
            }
            cerr<<endl;
            return;
        }
        
        if (tokens[0]=="resource") {
            
            if (tokens.size()<2) {
                cerr<<"missing resource name"<<endl;
                throw ResourceError::Parse;
            }
            
            stack.push_back(tokens[0]);
            next=follow[stack.back()];
            
            this->name=Name(tokens[1]);
        }
        
        if (tokens[0]=="atlas") {
            
            if (tokens.size()<4) {
                cerr<<"missing atlas arguments"<<endl;
                throw ResourceError::Parse;
            }
            
            stack.push_back(tokens[0]);
            next=follow[stack.back()];
            
            Node* node=new Node(tokens[3],"Atlas",current);
            current=node;
        }
        
        if (tokens[0]=="size") {
        }
        
        if (tokens[0]=="tile") {
            
            if (tokens.size()<4) {
                cerr<<"missing tile arguments"<<endl;
                
                throw ResourceError::Parse;
            }
            
            Node* node=new Node(tokens[3],"Tile",current);
        }
        
        if (tokens[0]=="dir") {
            
            if (tokens.size()<2) {
                cerr<<"missing dir name"<<endl;
                throw ResourceError::Parse;
            }
            
            stack.push_back(tokens[0]);
            
            Node* node = new Node(tokens[1],"Dir",current);
            current=node;
        }
        
        if (tokens[0]=="end") {
            
            if (stack.size()>0) {
                if (stack.back()=="dir") {
                    stack.pop_back();
                }
                else {
                    stack.pop_back();
                    next=follow[stack.back()];
                }
                current=current->parent;
            }
        }
        
    }
    
}
