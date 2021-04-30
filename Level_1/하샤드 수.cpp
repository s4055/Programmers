#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int k, sum = 0;
    
    k = x;
    while(k != 0){
        sum += (k%10);
        k /= 10;
    }
    
    if(x%sum != 0) answer = false;
    
    return answer;
}