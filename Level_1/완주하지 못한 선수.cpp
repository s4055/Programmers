#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
participant : 참가자
completion : 완주자

1. participant, completion을 오름차순 or 내림차순으로 정렬
2. participant과 completion을 비교하여 같지 않은 순간이 바로 완주하지 못한 사람
*/

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(int i = 0; i < participant.size(); i++){
        if(participant[i] != completion[i]){
            answer = participant[i];
            break;
        }
    }
    
    return answer;
}