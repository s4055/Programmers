#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int idx;
    
    s[0] = toupper(s[0]);
    answer += s[0];
    for(int i = 1; i < s.size(); i++){
        if(s[i] == ' '){
            s[i+1] = toupper(s[i+1]);
            idx = i+1;
        }

        if(i != idx){
            s[i] = tolower(s[i]);
        }
        answer += s[i];
    }
    
    return answer;
}