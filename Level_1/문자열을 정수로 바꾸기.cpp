#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int r = 1;
    if(s[0] == '+'){
        for(int i = s.size()-1; i >= 1; i--){
            answer += ((s[i]-'0')*r);
            r *= 10;
        }
    }
    else if(s[0] == '-'){
        for(int i = s.size()-1; i >= 1; i--){
            answer += ((s[i]-'0')*r);
            r *= 10;
        }
        answer *= -1;
    }
    else{
        for(int i = s.size()-1; i >= 0; i--){
            answer += ((s[i]-'0')*r);
            r *= 10;
        }
    }
    
    return answer;
}