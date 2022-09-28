#include<vector>
#include<queue>
using namespace std;
struct Loc{
    int x; int y;
};
int N, M;
int cnt;
bool flag;
bool map[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool isValid(int x, int y){
    if(x < 0 || y < 0 || x >= N || y >= M) return false;
    if(!map[x][y]) return false;
    return true;
}

void bfs(){
    queue<Loc> q;
    q.push({0, 0});
    while(!q.empty()){
        int size = q.size();
        for(int cycle = 0; cycle < size; cycle++){
            Loc loc = q.front(); q.pop();
            for(int i = 0; i < 4; i++){
                int nx = loc.x + dx[i];
                int ny = loc.y + dy[i];
                if(isValid(nx, ny)){
                    if(nx == N - 1 && ny == M - 1){
                        flag = true;
                        return;
                    }
                    q.push({nx, ny});
                    map[nx][ny] = false;
                }
            }
        }
        cnt++;
    }
}

int solution(vector<vector<int>> maps){
    int answer = 0;
    N = maps.size();
    M = maps[0].size();
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            map[i][j] = maps[i][j];
        }
    }
    bfs();
    if(flag) answer = cnt + 2;
    else answer = -1;
    
    return answer;
}