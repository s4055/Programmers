#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    // 오름차순 정렬
    sort(citations.begin(), citations.end());
    
    // cnt : h번 이상 인용된 논문 수
    int h = 0, max = -1, cnt;
    // h가 인용된 횟수가 가장 큰 값과 작거나 같을 때 까지 while
    while(h <= citations[citations.size()-1]){ 
        cnt = 0;
        for(int i = 0; i < citations.size(); i++){
            // h번 이상 인용된 논문 수 체크
            if(h <= citations[i]){
                cnt++;
            }
        }
        
        // h <= cnt : h번 이상 인용된 논문이 h편 이상 체크
        // h >= citations.size()-cnt : 나머지 논문이 h번 이하 인용 체크
        if(h <= cnt && h >= citations.size()-cnt){
            max = max > h ? max : h;
        }
        h++;
    }
    return max;
}