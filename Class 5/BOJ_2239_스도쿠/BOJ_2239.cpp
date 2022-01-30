#include <iostream>
using namespace std;

int board[9][9];

bool checkLine(int x, int y, int val){
    for(int i = 0; i < 9; i++){
        if(board[x][i] == val || board[i][y] == val) return false;
    }
    return true;
}

bool checkBox(int x, int y, int val){
    int nx = (x / 3) * 3;
    int ny = (y / 3) * 3;

    for(int i = nx; i < nx + 3; i++){
        for(int j = ny; j < ny + 3; j++){
            if(board[i][j] == val)
                return false;
        }
    }
    return true;
}

void backtracking(int cnt){
    if(cnt == 81){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cout << board[i][j];
            }
            cout << '\n';
        }
        exit(0); // 강제 종료
    }

    int x = cnt / 9;
    int y = cnt % 9;

    if(board[x][y] == 0){
        for(int k = 1; k <= 9; k++){
            if(checkLine(x, y, k) && checkBox(x, y, k)){
                board[x][y] = k;
                backtracking(cnt + 1);
                board[x][y] = 0;
            }
        }
    }
    else backtracking(cnt + 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    for(int i = 0; i < 9; i++){
        cin >> input;
        for(int j = 0; j < 9; j++)
            board[i][j] = input[j] - '0';
    }

    backtracking(0);
}