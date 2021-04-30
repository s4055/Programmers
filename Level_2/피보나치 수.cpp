#include <string>
#include <vector>

using namespace std;

vector<int> dp(100000, 0);

int fibo(int n){
    // // 첫 번째 풀이(시간 초과)
    // if(n == 0) return 0;
    // else if(n == 1) return 1;
    // else return (fibo(n-1) + fibo(n-2))%1234567;
    
    // 두 번째 풀이
    if(n == 1 || n == 2){
        return 1;
    }
    
    if(dp[n] != 0){
        return dp[n];
    }

    return dp[n] = (fibo(n-1) + fibo(n-2))%1234567;
}

int solution(int n) {
    int answer;
    answer = fibo(n);
    return answer;
}