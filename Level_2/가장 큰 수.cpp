#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string first, string second){
    return first + second > second + first;
}

string solution(vector<int> numbers) {
    vector<string> s;
    for(int i = 0; i < numbers.size(); i++){
        s.push_back(to_string(numbers[i]));
    }
    // 단순 숫자 비교가 아닌 두수를 합친 결과를 비교하여 내림차순
    sort(s.begin(), s.end(), compare);
    
    string answer = "";
    for(int i = 0; i < s.size(); i++){
        answer += s[i];
    }
    
    if(answer[0] == '0') return "0";
    return answer;
}