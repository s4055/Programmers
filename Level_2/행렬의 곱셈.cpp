#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    vector<int> v;
    int t = arr2[0].size();
    int sum, idx;
    
    // i : arr1의 행
    for(int i = 0; i < arr1.size(); i++){
        v.clear();
        idx = 0;// arr2의 열
        // r : 행*열 반복 횟수
        for(int r = 0; r < t; r++){
            sum = 0;
            // j : arr1의 열
            for(int j = 0; j < arr1[i].size(); j++){
                // 행*열의 값을 더함
                sum += arr1[i][j]*arr2[j][idx];
            }
            idx++;
            v.push_back(sum);
        }
        answer.push_back(v);
    }

    return answer;
}