#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0, k = -1;
    
    for(long long i = 1;; i++){
        if(i*i > n) break;
        if(i*i == n){
            k = i+1;
            break;
        }
    }
    
    if(k != -1) answer = k*k;
    else answer = k;
    
    return answer;
}