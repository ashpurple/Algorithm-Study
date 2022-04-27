#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct Loc{
    int x;
    int y;
};
int N, M;
int map[8][8];
bool visited[8][8];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int res = 0;

void init(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
            visited[i][j] = false;
    }
}

bool isValid(int x, int y, int temp[8][8]){
    if(x < 0 || y < 0 || x >= N || y >= M) return false;
    if(temp[x][y] != 0) return false;
    return true;
}

int bfs(queue<Loc> q, int temp[8][8]){
    
    while(!q.empty()){
        Loc loc = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int nx = dx[i] + loc.x;
            int ny = dy[i] + loc.y;
            if(isValid(nx, ny, temp) && !visited[nx][ny]){
                q.push({nx, ny});
                temp[nx][ny] = 2;
                visited[nx][ny] = true;
            }
        }
    }

    int sum = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(temp[i][j] == 0)
                sum++;
        }
    }
    return sum;
}

void dfs(int cnt, int wall){
    if(wall == 3){
        init();
        int sum;
        queue <Loc> q;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(map[i][j] == 2){
                    q.push({i, j});
                    visited[i][j] = true;
                }
            }
        }
        int temp[8][8];
        copy(&map[0][0], &map[0][0] + 64, &temp[0][0]);
        sum = bfs(q, temp);
        res = max(res, sum);
        return;
    }

    for(int i = cnt; i < N * M; i++){
        int x = cnt / M;
        int y = cnt % M;
        if(isValid(x, y, map)){
            map[x][y] = 1;
            dfs(cnt + 1, wall + 1);
            map[x][y] = 0;
        }
        cnt++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++)
            cin >> map[i][j];
    }
    dfs(0, 0);
    cout << res;
}