#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    int check[8] = {0,};
    string num = "0123456789";
    
    // 길이가 4 or 6 인지 확인
    if(s.size() == 4 || s.size() == 6){
        // 숫자로만 구성되어있는지 확인
        for(int i = 0; i < s.size(); i++){
            for(int j = 0; j < num.size(); j++){
                if(s[i] == num[j]){
                    check[i] = 1;
                }
            }
        }
        int sum = 0;
        for(int i = 0; i < s.size(); i++){
            sum += check[i];
        }
        if(s.size() == sum) return true;
        else return false;
    }
    return false;

}