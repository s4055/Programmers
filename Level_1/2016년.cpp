#include <string>
#include <vector>

using namespace std;

/*
day
0   1   2   3   4   5   6
일   월   화   수   목   금   토

month
각 월별로 1일이 무슨 요일인지
금   월   화   금   일   수   금   월   목   토   화   목
5   1   2   5   0   3   5   1   4   6   2   4

1. 주어진 월의 1일에서 +7을 하며 원하는 일이 나오는지 계산
2. 나오지 않는다면 2일에서 +7을 하며 원하는 일이 나오지는 계산
3. 위의 과정을 반복하여 값을 구함
    예를 들어 5월 25일인 경우 a = 5, b = 25
    5월 1일은 일요일이므로 month[a-1] = month[4] = 0
    1일부터 25일까지 총 24일이므로 (month[4] + 24)%7을 통해 요일을 구함

*/

string solution(int a, int b) {
    string answer = "";
    // 요일 저장
    vector<string> day;
    // 월별로 1일이 무슨 요일인지 나타내는 벡터
    vector<int> month;

    day.push_back("SUN");
    day.push_back("MON");
    day.push_back("TUE");
    day.push_back("WED");
    day.push_back("THU");
    day.push_back("FRI");
    day.push_back("SAT");

    month.push_back(5);
    month.push_back(1);
    month.push_back(2);
    month.push_back(5);
    month.push_back(0);
    month.push_back(3);
    month.push_back(5);
    month.push_back(1);
    month.push_back(4);
    month.push_back(6);
    month.push_back(2);
    month.push_back(4);

    for (int i = 1; i < 32; i++){
        for(int j = 0; j < 32; j+=7){
            if(i+j == b){
                answer += day[(month[a-1] + (b-1))%7];
                return answer;
            }
        }
    }
}