#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long r = 1;
    vector<int> v;
    while(n != 0){
        v.push_back(n%10);
        n /= 10;
    }
    // 오름차순 정렬
    sort(v.begin(), v.end());
    
    // 계산
    for(int i = 0; i < v.size(); i++){
        answer += (v[i]*r);
        r *= 10;
    }
    return answer;
}