#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    string al = "abcdefghijklmnopqrstuvwxyz";
    
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' ') answer += ' ';
        else{
            for(int j = 0; j < al.size(); j++){
                if(s[i] != ' ' && tolower(s[i]) == al[j]){
                    if(tolower(s[i]) == s[i]){
                        answer += al[(j+n)%26];
                    }
                    else{
                        answer += toupper(al[(j+n)%26]);
                    }
                }
            }
        }
    }
    return answer;
}