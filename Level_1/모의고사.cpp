#include <string>
#include <vector>

using namespace std;

int arr1[5] = {1, 2, 3, 4, 5}, arr2[8] = {2, 1, 2, 3, 2, 4, 2, 5}, arr3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> cnt(3);
    
    // 정답 갯수 세기
    for(int i = 0; i < answers.size(); i++){
        if(answers[i] == arr1[i%5]) cnt[0]++;
        if(answers[i] == arr2[i%8]) cnt[1]++;
        if(answers[i] == arr3[i%10]) cnt[2]++;
    }
    
    // cnt에서 가장 큰 수 찾기
    int max = (cnt[0] > cnt[1]) ? (cnt[0] > cnt[2] ? cnt[0] : cnt[2]) : (cnt[1] > cnt[2] ? cnt[1] : cnt[2]);
    
    for(int i = 0; i < cnt.size(); i++){
        if(cnt[i] == max){
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}