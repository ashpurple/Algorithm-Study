#include <iostream>
using namespace std;

char board[50][50];
char whiteBoard[8][8] = {
    'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W'
};
char blackBoard[8][8] = {
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
	'W','B','W','B','W','B','W','B',
	'B','W','B','W','B','W','B','W',
    'W','B','W','B','W','B','W','B',
};
int whiteBoardCount(int row, int col){
    int cnt = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(board[row + i][col + j] != whiteBoard[i][j])
                cnt++;
        }
    }
    
    return cnt;
}
int blackBoardCount(int row, int col){
    int cnt = 0;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(board[row + i][col + j] != blackBoard[i][j])
                cnt++;
        }
    }
    
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> board[i][j];
        }
    }

    int whiteCnt, blackCnt, min = 64;
    for(int i = 0; i <= N - 8; i++){
        for(int j = 0; j <= M - 8; j++){
            whiteCnt = whiteBoardCount(i, j);
            blackCnt = blackBoardCount(i, j);
            if(whiteCnt < blackCnt){
                if(whiteCnt < min)
                    min = whiteCnt;
            }
            else{
                if(blackCnt < min)
                    min = blackCnt;
            }
        }
    }
    cout << min;
    
}