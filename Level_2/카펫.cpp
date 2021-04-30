#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    // 노란 격자 가로 : x, 세로 : y, x > y
    // xy = 노란 격자 = yellow -> x, y는 yellow의 약수
    // 2x + 2y + 4 = 갈색 격자 = brown
    
    vector<int> answer;
    int x, y;
    for(int i = 1; i*i <= yellow; i++){
        if(yellow % i == 0){
            x = yellow / i;
            y = i;
            if(2*x + 2*y + 4 == brown){
                answer.push_back(x+2);
                answer.push_back(y+2);
                return answer;
            }
        }
    }
}