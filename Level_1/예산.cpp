#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int sum;

int solution(vector<int> d, int budget) {
    sum = 0;
    for(int i = 0; i < d.size(); i++){
        sum += d[i];
    }
    if(sum <= budget){
        return d.size();
    }
    
    sum = 0;
    sort(d.begin(), d.end());
    for(int i = 0; i < d.size(); i++){
        sum += d[i];
        if(sum > budget){
            return i;
        }
    }
}