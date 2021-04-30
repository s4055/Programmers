#include <string>
#include <vector>
#include <algorithm>
#define SIZE 10000000

using namespace std;

int era[SIZE] = {0,};
int visited[7] = {0,};
vector<int> result;
vector<int> tmp;

void func(int s, int cnt){
    result.push_back(s);

    if(cnt == tmp.size()){
        return;
    }

    for(int i = 0; i < tmp.size(); i++){
        if(visited[i] == 0){
            visited[i] = 1;
            func(stoi(to_string(s) + to_string(tmp[i])), cnt+1);
            visited[i] = 0;
        }
    }
}

int solution(string numbers) {
    // 소수 찾기
    era[0] = era[1] = 1;
    for(int i = 2; i < SIZE; i++){
        if(era[i] == 0){
            for(int j = i*2; j < SIZE; j+=i){
                era[j] = 1;
            }
        }
    }
    
    /* 계산 */
    for(int i = 0; i < numbers.size(); i++){
        tmp.push_back(numbers[i] - '0');
    }
    
    for(int i = 0; i < tmp.size(); i++){
        visited[i] = 1;
        func(tmp[i], 1);
        visited[i] = 0;
    }
    
    // 중복 제거
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    
    // 소수 갯수 찾기
    int answer = 0;
    for(int i = 0; i < result.size(); i++){
        if(era[result[i]] == 0) answer++;
    } 
    return answer;
}