#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    // 1. 다리 진입 조건
    // 진입할 공간이 있는지 -> 다리가 버틸 무게를 넘지 않는지
        // 진입할 공간이 있는지 : 가장 뒤에 있는 트럭의 위치 - 1 > 0
            // 다리가 버틸 무게를 넘지 않는지 : 다리에 진입한 트럭들의 무게의 합으로 비교
    
    // 2. 다리를 나오는 조건
    // 다리에 진입한 트럭 위치 = 다리 길이 + 1
    
    /* 풀이 */
    vector<pair<int, int>> tmp; // tmp : 트럭 무게, 트럭 위치
    int weight_sum, answer = 0, idx = 0; // answer : 걸리는 시간, weight_sum : 진입한 트럭 무게 합
    
    while(true){
        answer++;
        
        // 처음 시작 시
        if(tmp.size() == 0){
            tmp.push_back({truck_weights[idx++], 1});
        }
        // 두 번째 부터
        else{
            weight_sum = 0;
            
            // 진입한 트럭의 위치 이동 및 무게 합
            for(int i = 0; i < tmp.size(); i++){
                tmp[i].second += 1;
                // 무게 합(트럭 위치가 다리 길이보다 크다면 다리를 건넌 것으로 함)
                if(tmp[i].second <= bridge_length){
                    weight_sum += tmp[i].first;
                }
            }
            
            // 가장 마지막에 진입한 트럭 위치를 이용하여 진입 공간 여부 확인
            if(tmp[tmp.size()-1].second > 1){
                if(truck_weights.size() > idx && weight_sum + truck_weights[idx] <= weight){
                    tmp.push_back({truck_weights[idx++], 1});
                }
            }
            
            // 결과
            if(tmp[idx-1].second > bridge_length){
                return answer;
            }
        }
    }
}