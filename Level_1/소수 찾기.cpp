#include <string>
#include <vector>

using namespace std;

int era[1000001] = {0,};

int solution(int n) {
    era[0] = era[1] = 1;
    for(int i = 2; i < 1000001; i++){
        if(era[i] == 0){
            for(int j = i*2; j < 1000001; j+=i){
                era[j] = 1;
            }
        }
    }
    
    int answer = 0;
    for(int i = 2; i <= n; i++){
        if(era[i] == 0){
            answer++;
        }
    }
    return answer;
}