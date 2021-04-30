#include <string>
#include <vector>

using namespace std;

// 이진수 변환하여 1과 0의 갯수 리턴
vector<int> fun(int x){
    vector<int> v, result(2, 0);
    
    while(x != 0){
        v.push_back(x%2);
        x /= 2;
    }
    
    for(int i = 0; i < v.size(); i++){
        if(v[i] == 0) result[0]++;
        else result[1]++;
    }
    return result;
}

bool compare(vector<int> x, vector<int> y){
    if(x[1] == y[1]){
        return true;
    }
    else{
        return false;
    }

}

int solution(int n) {
    vector<int> a, b;
    int num = n;
    
    a = fun(n);
    while(true){
        num++;
        b = fun(num);
        if(compare(a, b)){
            return num;
        }
    }
}