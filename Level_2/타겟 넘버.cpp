#include <string>
#include <vector>

using namespace std;

int SIZE, TARGET, answer = 0;

void func(int sum, int cnt, vector<int> v){
    if(cnt == SIZE-1){
        if(TARGET == sum){
            answer++;
            return;
        }
        return;
    }

    cnt += 1;
    func(sum + v[cnt], cnt, v);
    func(sum + v[cnt]*-1, cnt, v);
}

int solution(vector<int> numbers, int target) {
    SIZE = numbers.size();
    TARGET = target;
    func(numbers[0], 0, numbers);
    func(numbers[0]*-1, 0, numbers);

    return answer;
}