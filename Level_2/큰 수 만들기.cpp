#include <string>
#include <vector>

using namespace std;

/*
max : idx+1 ~ k+idx+1에서 가장 큰 수 담는 변수
cnt : k에서 제외시킬 갯수를 담는 변수
tmp : max에서 구해진 i의 값을 담는 변수
size : while문 종료 후 나머지 변수를 answer에 담기 위해 사용되는 변수
idx : 찾는 범위를 표시하기 위한 변수

1. v에 number 값을 저장
2. k > 0 일때 까지 while문 실행
예)
인덱스     0   1   2   3   4   5   6   7   8   9
v       4   1   7   7   2   5   2   8   4   1

    2-1. v[0] ~ v[4]에서 가장 큰 수 찾기
    2-2. v[2] = 7로 가장 크므로 answer += '7'
    2-3. v[2]이므로 앞에 v[0], v[1]을 제외시켜야하므로 k = k - 2 = 2
    2-4. v[3] ~ v[5]에서 가장 큰 수 찾기
    2-5. v[3] = 7로 가장 크므로 answer += '7'
    2-6. v[3]이므로 제외시키야하는 것이 없으므로 k = 2
    2-7. v[4] ~ v[6]에서 가장 큰 수 찾기
    2-8. v[5] = 5로 가장 크므로 answer += '5'
    2-9. v[5]이므로 v[4]를 제외시켜야하므로 k = k - 1 = 1
    2-10. v[6] ~ v[7]에서 가장 큰 수 찾기
    2-11. v[7] = 8로 가장 크므로 answer += '8'
    2-12. v[7]이므로 v[6]를 제외시켜야하므로 k = k - 1 = 0
    2-13. 그 후 변수 size와 v.size()를 비교하여 남는 값들을 answer에 저장
    
3. 남은 값들이 있다면 if문 실행
*/

string solution(string number, int k) {
    string answer = "";
    vector<int> v;
    
    for(int i = 0; i < number.size(); i++){
        v.push_back(number[i] - '0');
    }
    
    int max, cnt, tmp, size = number.size()-k, idx = -1;
    while(k > 0){
        if(answer.size() == size){
            break;
        }
        
        max = -1;
        cnt = idx+1;
        for(int i = idx+1; i <= k+idx+1; i++){
            if(max < v[i]){
                max = v[i];
                tmp = i;
            }
        }
        answer += to_string(v[tmp]);
        k = k - (tmp - cnt);
        idx = tmp;
    }
    
    if(answer.size() != size){
        for(int i = idx+1; i < v.size(); i++){
            answer += to_string(v[i]);
        }
    }
    
    return answer;
}