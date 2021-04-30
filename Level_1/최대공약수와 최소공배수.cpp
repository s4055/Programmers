#include <string>
#include <vector>

using namespace std;

int gcd(int x, int y){
    if(y == 0) return x;
    else return gcd(y, x%y);
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    int result;
    
    if(n > m) result = gcd(n, m);
    else result = gcd(m, n);
    
    answer.push_back(result);
    answer.push_back((m*n)/result);
    
    return answer;
}