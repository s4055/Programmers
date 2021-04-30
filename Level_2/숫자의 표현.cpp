#include <string>
#include <vector>

using namespace std;

/*
for문을 통해 i = 1 ~ n/2 까지로 설정한 후 반복
j = i를 해서 j부터 +1한 값을 차례대로 더하여 n과 같은 비교
*/

int solution(int n) {
    int answer = 0;
    int sum, j;
    
    for(int i = 1; i <= n/2; i++){
        sum = 0;
        j = i;
        while(true){
            if(sum == n){
                answer++;
                break;
            }
            if(sum > n){
                break;
            }
            sum += j;
            j++;
        }
    }
    answer += 1; // 자기자신
    return answer;
}