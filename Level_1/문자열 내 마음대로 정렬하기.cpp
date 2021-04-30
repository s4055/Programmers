#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;

bool compare(string a, string b){
    if(a[N] != b[N]){
        return a[N] < b[N];
    }
    else{
        return a < b;
    }
}

vector<string> solution(vector<string> strings, int n) {
    N = n;
    sort(strings.begin(), strings.end(), compare);
    vector<string> answer;
    for(int i = 0; i < strings.size(); i++){
        answer.push_back(strings[i]);
    }
    return answer;
}