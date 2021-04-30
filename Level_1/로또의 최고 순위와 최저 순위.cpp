#include <string>
#include <vector>

using namespace std;

/*
0의 갯수에 따라 결과가 달라짐

(1) 0 : 1개
    5개 일치 : 1, 2
    4개 일치 : 2, 3
    3개 일치 : 3, 4
    2개 일치 : 4, 5
    1개 일치 : 5, 6
    0개 일치 : 6, 6

(2) 0 : 2개
    4개 일치 : 1, 3
    3개 일치 : 2, 4
    2개 일치 : 3, 5
    1개 일치 : 4, 6
    0개 일치 : 5, 6
    
(3) 0 : 3개
    3개 일치 : 1, 4
    2개 일치 : 2, 5
    1개 일치 : 3, 6
    0개 일치 : 4, 6
    
(4) 0 : 4개
    2개 일치 : 1, 5
    1개 일치 : 2, 6
    0개 일치 : 3, 6

(5) 0 : 5개
    1개 일치 : 1, 6
    0개 일치 : 2, 6
    
(6) 0 : 6개
    0개 일치 : 1, 6
    
(7) 0 : 없음
    단순 비교만 하면됨, 최고 순위 = 최저순위

*/

int func(int n){
    if(n == 6) return 1;
    else if(n == 5) return 2;
    else if(n == 4) return 3;
    else if(n == 3) return 4;
    else if(n == 2) return 5;
    else return 6;
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    // 0의 갯수를 담는 변수
    int zero = 0;
    for(int i = 0; i < lottos.size(); i++){
        if(lottos[i] == 0) zero++;
    }
    
    // lottos와 win_nums에서 일치하는 번호 갯수를 담는 변수
    int check = 0;
    int visited[6] = {0,};
    for(int i = 0; i < lottos.size(); i++){
        for(int j = 0; j < win_nums.size(); j++){
            if(visited[i] == 0 && lottos[i] == win_nums[j]){
                visited[i] = 1;
                check++;
            }
        }
    }
    
    answer.push_back(func(zero+check));
    answer.push_back(func(check));
    return answer;
}