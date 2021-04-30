#include <vector>
#include <iostream>

using namespace std;

/*
1. answer에 순서대로 저장
    answer의 마지막과 저장하려는 값이 같지 않아야한다.
*/

vector<int> solution(vector<int> arr) {
    vector<int> answer;

    for(int i = 0; i < arr.size(); i++){
        if(i == 0) answer.push_back(arr[i]);
        else{
            if(answer[answer.size()-1] != arr[i]){
                answer.push_back(arr[i]);
            }
        }
    }

    return answer;
}