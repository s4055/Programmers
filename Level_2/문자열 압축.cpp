#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
int check cnt = 0;

i = n
for(int j = 0; j < s.size()-n; j+=n){
    check = 0;
    for(int k = j; k < j+n; k++){
        if(s[k] == s[k+2]){
            check++;
        }
    }
    if(check == n){
        cnt++;
    }
    else{
        //반복횟수 : cnt+1, 단어 : 인덱스(j <= idx < j+n)
        cnt = 0;
    }
}
*/

int solution(string s){
    int answer = 1000;
    int endPoint, cnt, check; // cnt : 반복 횟수, check : 반복여부 확인용
    vector<bool> boolean;
    string tmp;

    s += ' ';

    // i : 나누는 단위
    for (int i = 1; i < s.size(); i++){
        cnt = 0;
        tmp = "";

        // i 단위로 얼만큼 반복되는지 비교
        for (int j = 0; j < s.size() - i; j += i){
            check = 0;
            boolean.clear();
            endPoint = j + i;
            for (int k = j; k < j + i; k++){
                if (s[k] == s[k + i]) boolean.push_back(true);
                else boolean.push_back(false);
            }

            // boolean에 담긴 값을 이용해서 모두 일치하는지 확인
            for (int x = 0; x < boolean.size(); x++){
                // 일치하지 않는 것이 있다면 check = 1
                if (boolean[x] == false) check = 1;
            }

            if (check == 0) cnt++;
            else{
                //반복횟수 : cnt+1, 단어 : 인덱스(j <= idx < j+i)
                if (cnt != 0) tmp += to_string(cnt + 1);

                for (int x = j; x < j + i; x++){
                    tmp += s[x];
                }
                cnt = 0;
            }
        }

        // 나누는 단위(i)에 따라 나누어 지지 않는 부분이 있기 때문에 endPoint를 이용해서 남은 값을 tmp에 담기
        if (endPoint < s.size()){
            for (int x = endPoint; x < s.size(); x++){
                tmp += s[x];
            }
        }

        // 계산하기 위해 s에 공백추가한 것을 제거
        tmp.erase(remove(tmp.begin(), tmp.end(), ' '), tmp.end());
        // 압축율 비교
        answer = answer > tmp.size() ? tmp.size() : answer;
    }
    return answer;
}