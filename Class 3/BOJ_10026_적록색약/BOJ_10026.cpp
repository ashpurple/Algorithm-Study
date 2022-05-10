#include <iostream>
#include <queue>
using namespace std;
struct Loc{
    int x;
    int y;
};

int N;
char map[100][100];
bool visited[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int cnt = 0, cnt2 = 0;

bool isValid(int x, int y, char color, bool colorLess){
    if(x < 0 || y < 0 || x >= N || y >= N) return false;
    if(visited[x][y]) return false;
    if(colorLess){
        if(color == 'R' && map[x][y] == 'G') return true;
        if(color == 'G' && map[x][y] == 'R') return true;
        if(color != map[x][y]) return false;
    }
    else{
        if(color != map[x][y]) return false;
    }
    
    return true;
}

void bfs(int x, int y, char color, bool colorLess){
    queue<Loc> q;
    q.push({x, y});
    visited[x][y] = true;
    while(!q.empty()){
        Loc loc = q.front(); q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = loc.x + dx[i];
            int ny = loc.y + dy[i];
       
            if(isValid(nx, ny, color, colorLess)){
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string row;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> row;
        for(int j = 0; j < N; j++)
            map[i][j] = row[j]; 
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visited[i][j]){
                bfs(i, j, map[i][j], false);
                cnt++;
            }
        } 
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            visited[i][j] = false;
        } 
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(!visited[i][j]){
                bfs(i, j, map[i][j], true);
                cnt2++;
            }
        } 
    }
    cout << cnt << ' ' << cnt2;
}