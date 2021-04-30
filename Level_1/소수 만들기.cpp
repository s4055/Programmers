#include <vector>
#include <iostream>
using namespace std;

int era[50001] = {0,};

int solution(vector<int> nums) {
    // 소수 구하기
    era[0] = era[1] = 1;
    for(int i = 2; i < 50001; i++){
        if(era[i] == 0){
            for(int j = i*2; j < 50001; j+=i){
                era[j] = 1;
            }
        }
    }
    
    int cnt = 0;
    for(int i = 0; i < nums.size()-2; i++){
        for(int j = i+1; j < nums.size()-1; j++){
            for(int k = j+1; k < nums.size(); k++){
                if(era[nums[i] + nums[j] + nums[k]] == 0){
                    cnt++;
                }
            }
        }
    }
    return cnt;
}