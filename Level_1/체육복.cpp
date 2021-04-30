#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    // student는 학생이 가지고 있는 체육복의 수를 나타냄
    // 따라서 초기값은 1
    vector<int> student(n, 1);
    
    // 도난 : 0
    for(int i = 0; i < lost.size(); i++){
        student[lost[i]-1]--;
    }
    
    // 여벌 옷 : 1
    for(int i = 0; i < reserve.size(); i++){
        student[reserve[i]-1]++;
    }
    
    // 여벌 옷 나눠주기
    for(int i = 0; i < student.size(); i++){
        if(student[i] == 2){
            if(student[i-1] == 0 && i >= 1) {
                student[i-1]++;
                student[i]--;
            }
            else if(student[i+1] == 0 && i < student.size()-1) {
                student[i+1]++;
                student[i]--;
            }
        }
    }
    
    // 참여할 수 있는 인원 검사
    int answer = 0;
    for(int i = 0; i < student.size(); i++){
        if(student[i] > 0) answer++;
    }
    return answer;
}