#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    for(int i = 0; i < s.size(); i++){
        s[i] = tolower(s[i]);
    }
    
    int p = 0, y = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'p') p++;
        if(s[i] == 'y') y++;
    }
    
    if(p == y) answer = true;
    else if(p != y) answer = false;
    else if(p == 0 && y == 0) answer = true;
    return answer;
}