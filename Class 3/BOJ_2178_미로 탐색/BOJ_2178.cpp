#include <iostream>
#include <queue>
using namespace std;
struct Loc{
    int x;
    int y;
    int cnt;
};
int N, M;
bool map[100][100];
bool visited[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool isValid(int x, int y){
    if(x < 0 || x >= N || y < 0 || y >= M) return false;
    if(!map[x][y]) return false;
    if(visited[x][y]) return false;
    
    return true;
}

int bfs(){
    queue<Loc> q;
    q.push({0, 0, 1});
    visited[0][0] = true;
    while(!q.empty()){
        Loc loc = q.front(); q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = loc.x + dx[i];
            int ny = loc.y + dy[i];
            int cnt = loc.cnt;

            if(isValid(nx, ny)){
                if(nx == N - 1 && ny == M - 1) return cnt + 1;
                q.push({nx, ny, cnt + 1});
                visited[nx][ny] = true;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    string input;
    for(int i = 0; i < N; i++){
        cin >> input;
        for(int j = 0; j < M; j++)
            map[i][j] = input[j] - '0';
    }

    cout << bfs();

}