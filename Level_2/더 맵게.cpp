#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    // 최소 힙(오름차순)
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < scoville.size(); i++){
        pq.push(scoville[i]);
    }
    
    int first, second, answer = 0;
    while(pq.top() < K){
        // 마지막까지 계산을 하여도 만족하지 않는다면
        if(pq.size() == 1 && pq.top() < K){
            return -1;
        }
        first = pq.top();
        pq.pop();
        second = pq.top();
        pq.pop();
        pq.push(first + (second * 2));
        answer++;
    }
    return answer;
}