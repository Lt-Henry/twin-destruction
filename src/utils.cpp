
#include "utils.hpp"

using namespace std;

vector<string> twin::split(string line,char sep)
{
    vector<string> tokens;
    
    bool knee=false;
    string tmp;

    for (char c : line) {

        if (c==sep) {
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