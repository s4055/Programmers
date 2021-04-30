#include <string>
#include <vector>

using namespace std;

/*
1. 3진법으로 나타낸 뒤 앞에서 부터 3^n으로 해서 나온 결과를 리턴
*/

int solution(int n) {
    int answer = 0;
    
    vector<int> v;
    // 3진법
    while(n >= 3){
        v.push_back(n%3);
        n /= 3;
    }
    v.push_back(n);
    
    int r = 1;
    for(int i = v.size()-1; i >= 0; i--){
        answer += v[i]*r;
        r *= 3;
    }
    return answer;
}