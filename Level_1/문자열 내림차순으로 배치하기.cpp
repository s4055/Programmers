#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b){
    return a > b;
}

string solution(string s) {
    string answer = "";
    vector<string> v(s.size());

    for(int i = 0; i < s.size(); i++){
        v[i] = s[i];
    }
    
    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < v.size(); i++){
        answer += v[i];
    }
    return answer;
}