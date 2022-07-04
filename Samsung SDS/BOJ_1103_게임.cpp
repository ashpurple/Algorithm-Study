#include <iostream>
using namespace std;
int N, M;
char board[50][50];
bool visited[50][50];
int dp[50][50];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool isCycle;
int cnt = 0;

bool isValid(int x, int y, int dir){
    if(x < 0 || x >= N || y < 0 || y >= M) return false;
    if(board[x][y] == 'H') return false;
    if(visited[x][y]){
        isCycle = true;
        return false;
    }
    return true;
}

void dfs(int x, int y, int depth){
    if(isCycle) return;
    visited[x][y] = true;
    cnt = max(cnt, depth);
    dp[x][y] = depth;

    for (int i = 0; i < 4; i++){
        int num = board[x][y] - '0';
        int nx = x + (dx[i] * num);
        int ny = y + (dy[i] * num);
        if (!isValid(nx, ny, i)) continue;
        if(dp[nx][ny] > 0 && depth < dp[nx][ny]) continue;
        dfs(nx, ny, depth + 1);
    }
    visited[x][y] = false; // end node
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        string input;
        cin >> input;
        for(int j = 0; j < M; j++){
            board[i][j] = input[j];
        }
    }
    dfs(0, 0, 1);
    if(isCycle) cout << -1;
    else cout << cnt;
}

