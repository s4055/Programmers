#include <string>
#include <vector>

using namespace std;

int check(string str, int idx){
    if(str[idx-1]-'0' != 0) return str[idx-1] - '0';
    else{
        if(str[idx-2]-'0' == 1) return 10;
        else return 0;
    }
}

int solution(string dartResult) {
    int answer = 0, k;
    // 각 점수별로 구분하기 위한 변수
    vector<int> v;
    
    for(int i = 0; i < dartResult.size(); i++){
        if(dartResult[i] == 'S'){
            k = check(dartResult, i);
            v.push_back(k);
        }
        else if(dartResult[i] == 'D'){
            k = check(dartResult, i);
            v.push_back(k*k);
        }
        else if(dartResult[i] == 'T'){
            k = check(dartResult, i);
            v.push_back(k*k*k);
        }
        else if(dartResult[i] == '*'){
            if(v.size() == 1) v[0] = v[0]*2;
            else{
                v[v.size()-1] = v[v.size()-1]*2;
                v[v.size()-2] = v[v.size()-2]*2;
            }
        }
        else if(dartResult[i] == '#'){
            v[v.size()-1] = v[v.size()-1]*-1;
        }
    }
    
    for(int i = 0; i < v.size(); i++){
        answer += v[i];
    }
    return answer;
}