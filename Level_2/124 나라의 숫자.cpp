#include <string>
#include <vector>

using namespace std;

/*
3진법과 비슷하며 나머지가 0이 되면 0을 4로 바꾸고 남은 몫에서 -1을 하여 반복
*/

string solution(int n) {
    string answer = "";
    
    while(n != 0){
        if(n%3 == 0){
            answer = '4' + answer;
            n = (n/3) - 1;
        }
        else{
            answer = to_string(n%3) + answer;
            n /= 3;
        }
    }
    
    return answer;
}