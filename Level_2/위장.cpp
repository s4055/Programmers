#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
1. 의상의 종류가 몇 개인지 kind
2. kind에서 중복 제거
3. v에 의상의 종류별로 몇 개씩 있는지 저장
4. v에 저장된 값을 각각 +1을 한 후 모두 곱함
    의상의 종류를 선택하지 않은 경우를 생각해서 +1
5. 4에서 구한 값에 -1을 리턴
    +1을 하면 의상의 모두 입지 않은 경우가 있기 때문에 -1
*/

int solution(vector<vector<string>> clothes) {
    // 의상의 종류를 kind 저장
    vector<string> kind;
    for(int i = 0; i < clothes.size(); i++){
        kind.push_back(clothes[i][1]);
    }
    
    // kind에 중복 제거
    sort(kind.begin(), kind.end());
    kind.erase(unique(kind.begin(), kind.end()), kind.end());
    
    // 각 의상의 종류별 의상의 수
    // v의 크기 : kind.size()
    // v의 초기값 : 0
    vector<int> v(kind.size(), 0);
    for(int i = 0; i < clothes.size(); i++){
        for(int j = 0; j < kind.size(); j++){
            if(clothes[i][1] == kind[j]){
                v[j]++;
            }
        }
    }
    
    // 결과
    // 해당 의상을 고르지 않는 경우를 추가하여
    // 모든 의상의 종류별 의상의 수에 +1
    // 모든 의상의 종류별 의상의 수를 모두 곱하면
    // 모든 의상을 고르지 않는 경우도 포함되기 때문에 결과 값에서 -1
    int result = 1;
    for(int i = 0; i < v.size(); i++){
        result *= (v[i] + 1);
    }
    return (result - 1);
}