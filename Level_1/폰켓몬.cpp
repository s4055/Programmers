#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0, N;
    N = nums.size();
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    
    if(N/2 <= nums.size()) answer = N/2;
    else answer = nums.size();
    
    return answer;
}