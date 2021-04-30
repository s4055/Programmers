#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id) {
    string s, answer = "";
    string sample = "abcdefghijklmnopqrstuvwxyz0123456789-_.";
    bool check;
    vector<int> idx;
    int k;
    
    // 첫번째
    for(int i = 0; i < new_id.size(); i++){
        new_id[i] = tolower(new_id[i]);
    }
    
    // 두번째
    for(int i = 0; i < new_id.size(); i++){
        check = true;
        for(int j = 0; j < sample.size(); j++){
            if(new_id[i] == sample[j]){
                check = false;
            }
        }
        if(check){
            idx.push_back(i);
        }
    }

    k = 0;
    for(int i = 0; i < idx.size(); i++){
        new_id = new_id.substr(0, idx[i]-k) + new_id.substr((idx[i]-k)+1, new_id.size());
        k++;
    }
    idx.clear();
    
    // 세번째
    k = -1;
    for(int i = 0; i < new_id.size(); i++){
        check = true;
        if(new_id[i] == new_id[i+1] && new_id[i] == '.'){
            if(k == -1) k = i;
            check = false;
        }
        if(check && k != -1){
            idx.push_back(k);
            idx.push_back(i);
            k = -1;
        }
    }

    k = 0;
    for(int i = 0; i < idx.size(); i+=2){
        new_id = new_id.substr(0, idx[i]-k) + '.' + new_id.substr((idx[i+1]-k)+1, new_id.size());
        k += (idx[i+1] - idx[i]);
    }

    
    // 네번째
    if(new_id[0] == '.'){
        new_id = new_id.substr(1, new_id.size());
    }
    if(new_id[new_id.size()-1] == '.'){
        new_id = new_id.substr(0, new_id.size()-1);
    }
    
    // 다섯번째
    if(new_id == ""){
        new_id += "a";
    }
    
    // 여섯번째
    if(new_id.size() >= 16){
        new_id = new_id.substr(0, 15);
        
        if(new_id[14] == '.'){
            new_id = new_id.substr(0, 14);
        }
    }

    // 일곱번째
    k = new_id.size();
    if(k <= 2){
        s = new_id[k-1];

        for(int i = 0; i < (3-k); i++){
            new_id += s;
        }
    }
    
    // 결과
    answer = new_id;
    return answer;
}