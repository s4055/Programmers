#include <string>
#include <vector>
#include <cstring>

using namespace std;

/*
1. phone = phone_book[i]
2. 현재 phone에 저장된 문자열을 제외(i != j)하고 접두어로 일치하는 것이 있는지 확인
    
*/

bool solution(vector<string> phone_book) {
    string phone = "";
    for(int i = 0; i < phone_book.size(); i++){
        phone = phone_book[i];
        for(int j = 0; j < phone_book.size(); j++){
            // 비교하는 것이 자기자신이 아니면서 접두사로 쓰이는지 체크
            if(i != j && phone == phone_book[j].substr(0, phone.size())){
               return false;
            }
        }
    }
    return true;
}