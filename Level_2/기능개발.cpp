#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    // 작업을 완료하기 위해 최소 몇 일이 필요한지 queue<int> tmp에 저장
    int k;
    queue<int> tmp;
    for(int i = 0; i < progresses.size(); i++){
        if((100 - progresses[i]) < speeds[i]){
            tmp.push(1);
        }
        else{
            k = (100 - progresses[i]) / speeds[i];
            if(100 - progresses[i] > speeds[i]*k){
                k++;
            }
            tmp.push(k);
        }
    }
    
    // 먼저 들어온 수를 저장하여 pop() 한 뒤 소요 일 수를 비교
    int n, cnt;
    while(!tmp.empty()){
        n = tmp.front();
        tmp.pop();
        cnt = 1;
        
        while(n >= tmp.front() && !tmp.empty()){
            tmp.pop();
            cnt++;
        }
        answer.push_back(cnt);
    }
    
    return answer;
}