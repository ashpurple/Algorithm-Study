#include <string>
#include <vector>
using namespace std;

int simulate(int m, int n, vector<string> &board){
    bool check[30][30] = {false, };
    for(int i = 0; i < m - 1; i++){
        for(int j = 0; j < n - 1; j++){
            if(board[i][j] == ' ') continue;
            if(board[i][j] == board[i + 1][j] &&
               board[i][j] == board[i][j + 1] &&
               board[i][j] == board[i + 1][j + 1]){
                check[i][j] = true;
                check[i + 1][j] = true;
                check[i][j + 1] = true;
                check[i + 1][j + 1] = true;
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(check[i][j]){
                board[i][j] = ' ';
                cnt++;
            }
        }
    }
    
    for(int j = 0; j < n; j++){
        for(int i = m - 1; 0 < i; i--){
            if(board[i][j] == ' '){
                for(int h = i - 1; 0 <= h; h--){
                    if(board[h][j] != ' '){
                        swap(board[i][j], board[h][j]);
                        break;
                    }
                }
            }
        }
    }
    
    return cnt;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while(true){
        int score = simulate(m, n, board);
        if(score == 0) break;
        answer += score;
    }
    
    return answer;
}