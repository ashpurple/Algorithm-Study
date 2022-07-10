#include <vector>
#include <queue>
using namespace std;
struct Loc{
    int x; int y;
};
int map[100][100];
bool visited[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int N, M;

bool isValid(int x, int y){
    if(x < 0 || x >= N || y < 0 || y >= M) return false;
    if(visited[x][y]) return false;
    if(map[x][y] == 1) return false;
    return true;
}

void sea(){
    queue<Loc> q;
    q.push({0, 0});
    visited[0][0] = true;
    while(!q.empty()){
        Loc loc = q.front(); q.pop();
        map[loc.x][loc.y] = -1;
        for(int i = 0; i < 4; i++){
            int nx = dx[i] + loc.x;
            int ny = dy[i] + loc.y;
            if(isValid(nx, ny)){
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

int bfs(int i, int j){
    int cnt = 0;
    queue<Loc> q;
    q.push({i, j});
    visited[i][j] = true;
    while(!q.empty()){
        Loc loc = q.front(); q.pop();
        cnt++;
        for(int i = 0; i < 4; i++){
            int nx = dx[i] + loc.x;
            int ny = dy[i] + loc.y;
            if(isValid(nx, ny)){
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
    return cnt;
}

vector<int> solution(int rows, int columns, vector<vector<int>> lands) {
    vector<int> answer;
    N = rows; M = columns;
    for(vector<int> land : lands){
        int x = land[0];
        int y = land[1];
        map[x - 1][y - 1] = 1;
    }

    sea();
    int maxCnt = 0;
    int minCnt = 10000;

    for(int i = 1; i < N - 1; i++){
        for(int j = 1; j < M - 1; j++){
            if(map[i][j] == 0 && !visited[i][j]){
                int cnt = bfs(i, j);
                maxCnt = max(maxCnt, cnt);
                minCnt = min(minCnt, cnt);
            }
        }
    }
    if(maxCnt == 0){
        answer.push_back(-1);
        answer.push_back(-1);
    }
    else{
        answer.push_back(minCnt);
        answer.push_back(maxCnt);
    }

    return answer;
}