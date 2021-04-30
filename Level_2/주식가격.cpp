#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    // 가격이 떨어지는 순간 break하여 idx - i를 하여 가격이 떨이지는 않은 기간을 push_back
    int idx;
    for(int i = 0; i < prices.size(); i++){
        for(int j = i+1; j < prices.size(); j++){
            idx = j;
            if(prices[i] > prices[j]){
                break;
            }
        }
        answer.push_back(idx - i);
    }
    return answer;
}