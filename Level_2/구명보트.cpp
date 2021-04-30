#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
구명보트를 최소 사용하려면 구명보트 당 최대한 많은 사람이 타야한다. 단, 최대 2명까지
그러므로 people을 오름차순으로 정렬한 뒤 가장 작은 수와 가장 큰 수의 합이 limit보다 작거나 같다면
2명을 구명보트에 태우고 만약에 limit보다 크다면 가장 큰 수만 구명보트에 태울 수 있고 
그 후 그 다음으로 큰 수와 가장 작은 수의 합을 limit와 비교하는 과정을 반복
*/

int solution(vector<int> people, int limit) {
    // 오름차순
    sort(people.begin(), people.end());
    
    int start = 0;
    int end = people.size() - 1;
    int cnt = 0;
    while(cnt != people.size()){
        if(start > end) break;

        if(people[start] + people[end] <= limit){
            cnt++;
            start++;
            end--;
        }
        else{
            cnt++;
            end--;
        }
    }
    
    return cnt;
}