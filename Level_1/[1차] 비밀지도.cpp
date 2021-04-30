#include <string>
#include <vector>

using namespace std;

/*
0, ' ' : 공백
1, # : 벽
하나라도 벽이라면 전체 지도는 벽
모두 공백이면 전체 지도는 공백
*/

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    string str;
    
    for(int i = 0; i < arr1.size(); i++){
        str = "";
        for(int j = 0; j < n; j++){
            if(arr1[i]%2 || arr2[i]%2){
                str = "#" + str;
            }
            else{
                str = " " + str;
            }
            arr1[i] = arr1[i]/2;
            arr2[i] = arr2[i]/2;  
        }
        answer.push_back(str);
    }
    return answer;
}