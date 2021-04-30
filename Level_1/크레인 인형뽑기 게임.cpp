#include <string>
#include <vector>

using namespace std;

/*
1. board와 moves를 통해 바구니(tmp)에 담기
2. 바구니(tmp)에 담은 후 바구니(tmp)에서 마지막과 뒤에서 두번째가 같다면 바구니(tmp)에서 빼고 터뜨려지면 인형 수를 +2
*/

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> tmp;
    for(int i = 0; i < moves.size(); i++){
        for(int j = 0; j < board.size(); j++){
            if(board[j][moves[i]-1] > 0){
                tmp.push_back(board[j][moves[i]-1]);
                board[j][moves[i]-1] = 0;
                break;
            }
        }
        if(tmp[tmp.size()-1] == tmp[tmp.size()-2]){
            tmp.pop_back();
            tmp.pop_back();
            answer += 2;
        }
    }
    
    return answer;
}