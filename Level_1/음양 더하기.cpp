#include <string>
#include <vector>

using namespace std;

/*
1. sum에 absolutes[i]와 signs[i]를 이용하여 계속 더함
*/

int solution(vector<int> absolutes, vector<bool> signs) {
    int sum = 0;
    for(int i = 0; i < absolutes.size(); i++){
        if(signs[i]) sum += absolutes[i];
        else sum += (absolutes[i]*-1);
    }
    
    return sum;
}