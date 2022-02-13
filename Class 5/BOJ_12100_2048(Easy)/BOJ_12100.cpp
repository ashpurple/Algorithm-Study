#include <iostream>
using namespace std;

int N, res;
int board[20][20];
bool visited[20][20];
int backup[5][20][20];

void init(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) 
            visited[i][j] = false;
    }
}

void up(){
    init();
    for(int j = 0; j < N; j++){
        for(int i = 1; i < N; i++){
            if(!board[i][j]) continue; // zero

            int idx = i;
            for(int k = 0; k < i; k++){ // drop
                if(!board[k][j]){
                    swap(board[k][j], board[i][j]);
                    idx = k;
                    break;
                }
            }

            if(idx == 0) continue;

            if(board[idx][j] == board[idx - 1][j]){ // same
                if(visited[idx - 1][j]) continue;
                visited[idx - 1][j] = true;
                board[idx][j] = 0;
                board[idx - 1][j] <<= 1;
            }
        }
    }
}

void down(){
    init();
    for(int j = 0; j < N; j++){
        for(int i = N - 2; 0 <= i; i--){
            if(!board[i][j]) continue; // zero

            int idx = i;
            for(int k = N - 1; i < k; k--){ // drop
                if(!board[k][j]){
                    swap(board[k][j], board[i][j]);
                    idx = k;
                    break;
                }
            }

            if(idx == N - 1) continue;

            if(board[idx][j] == board[idx + 1][j]){ // same
                if(visited[idx + 1][j]) continue;
                visited[idx + 1][j] = true;
                board[idx][j] = 0;
                board[idx + 1][j] <<= 1;
            }
        }
    }
}

void right(){
    init();
    for(int i = 0; i < N; i++){
        for(int j = N - 2; 0 <= j; j--){
            if(!board[i][j]) continue; // zero

            int idx = j;
            for(int k = N - 1; j < k; k--){ // drop
                if(!board[i][k]){
                    swap(board[i][k], board[i][j]);
                    idx = k;
                    break;
                }
            }

            if(idx == N - 1) continue;

            if(board[i][idx] == board[i][idx + 1]){ // same
                if(visited[i][idx + 1]) continue;
                visited[i][idx + 1] = true;
                board[i][idx] = 0;
                board[i][idx + 1] <<= 1;
            }
        }
    }
}

void left(){
    init();
    for(int i = 0; i < N; i++){
        for(int j = 1; j < N; j++){
            if(!board[i][j]) continue; // zero

            int idx = j;
            for(int k = 0; k < j; k++){ // drop
                if(!board[i][k]){
                    swap(board[i][k], board[i][j]);
                    idx = k;
                    break;
                }
            }

            if(idx == 0) continue;

            if(board[i][idx] == board[i][idx - 1]){ // same
                if(visited[i][idx - 1]) continue;
                visited[i][idx - 1] = true;
                board[i][idx] = 0;
                board[i][idx - 1] <<= 1;
            }
        }
    }
}

void copyBoard(int A[20][20], int B[20][20]){ // A to B
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) 
            B[i][j] = A[i][j];
    }
}

int getMax(){
    int maxValue = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            maxValue = max(maxValue, board[i][j]);
        }
    }
    return maxValue;
}

void simulate(int cnt){
    if(cnt == 5){
        for(int i = 0; i < N; i++) {
            int maxValue = getMax();
            res = max(maxValue, res);
        }
        return;
    }

    copyBoard(board, backup[cnt]);

    up();
    simulate(cnt + 1);
    copyBoard(backup[cnt], board);

    down();
    simulate(cnt + 1);
    copyBoard(backup[cnt], board);

    right();
    simulate(cnt + 1);
    copyBoard(backup[cnt], board);

    left();
    simulate(cnt + 1);
    copyBoard(backup[cnt], board);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> board[i][j];
        }
    }
    
   simulate(0);
   cout << res;
}