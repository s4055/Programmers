#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> result;
    
    for(int row = 0; row < commands.size(); row++){
        result.clear();
        for(int i = commands[row][0]-1; i < commands[row][1]; i++){
            result.push_back(array[i]);
        }
        sort(result.begin(), result.end());
        answer.push_back(result[commands[row][2] -1]);
    }
    
    return answer;
}