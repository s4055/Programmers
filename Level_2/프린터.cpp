#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<int> q, cq;
    for(int i = 0; i < priorities.size(); i++){
        q.push(priorities[i]);
    }
    
    int tmp, search = priorities[location], answer = 0;
    bool check;
    while(true){
        check = false;
        while(!cq.empty()){
            q.push(cq.front());
            cq.pop();
        }

        tmp = q.front();
        q.pop();
        
        for(int i = 1; i < priorities.size(); i++){
            if(tmp < priorities[i]){
                check = true;
                break;
            }
        }

        if(check == true){
            q.push(tmp);
        }
        else{
            answer++;
            
            if(location == 0 && tmp == search){
                return answer;
            }
        }
        
        // location 이동
        if(location != 0) location -= 1;
        else location = q.size() - 1;

        priorities.clear();
        while(!q.empty()){
            priorities.push_back(q.front());
            cq.push(q.front());
            q.pop();
        }
    }
}