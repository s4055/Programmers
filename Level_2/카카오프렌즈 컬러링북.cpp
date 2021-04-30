#include <vector>
#include <queue>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer; // 정답을 담는 변수
    int visited[100][100] = {0,}; // 방문 여부를 확인
    int position[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 상하좌우를 이동할 때 사용할 변수
    int x, y, a, b;
    int field = 0, erea = -1, cnt; //field : 영역 수, erea : 가장 큰 넓이, cnt : 넓이
    queue<pair<int, int>> q;
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            // 방문하지 않았고 영역이 칠해져있다면
            if(visited[i][j] == 0 && picture[i][j] != 0){
                cnt = 1; // if문이 true이므로 넓이를 1로 지정
                field++; // if문이 true이므로 영역수 증가
                q.push({i, j});
                visited[i][j] = 1; // 방문
                while(!q.empty()){
                    a = q.front().first;
                    b = q.front().second;
                    q.pop();
                    for(int row = 0; row < 4; row++){
                        x = a + position[row][0];
                        y = b + position[row][1];
                        
                        // position 배열을 이용하여 구한 x, y가 배열 범위에 포함되고 방문하지 않고 picutre[i][j]와 같다면
                        if(0 <= x && x < m && 0 <= y && y < n && picture[i][j] == picture[x][y] && visited[x][y] == 0){
                            q.push({x, y});
                            visited[x][y] = 1;
                            cnt++;
                        }
                    }
                }
                erea = erea > cnt ? erea : cnt;
            }
        }
    }
    answer.push_back(field);
    answer.push_back(erea);
    return answer;
}