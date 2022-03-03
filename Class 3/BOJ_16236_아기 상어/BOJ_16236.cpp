#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
struct Loc{
    int x;
    int y;
    int level;
    int cnt;
    int time;
    bool operator<(const Loc l) const{
        if(x == l.x) return y > l.y;
        return x > l.x;
    }
};
int N;
int map[20][20];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
bool visited[20][20];
int ans;
int timeFlag;
bool flag;

bool isPossible(int x, int y, int level){
    if(x < 0 || x >= N || y < 0 || y >= N) return false;
    if(visited[x][y]) return false;
    if(level < map[x][y]) return false;
    return true;
}

void bfs(Loc start){
    queue <Loc> q;
    priority_queue <Loc> cand;
    q.push(start);
    visited[start.x][start.y] = true;

    while(!q.empty()){
        Loc cur = q.front(); q.pop();
        
        for(int i = 0; i < 4; i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            int level = cur.level;
            int cnt = cur.cnt;
            int time = cur.time + 1;
            
            if(isPossible(nx, ny, level)){
                if(map[nx][ny] != 0 && map[nx][ny] < level){ // can eat
                    cand.push({nx, ny, level, cnt, time});
                    q.push({nx, ny, level, cnt, time});
                }
                else{
                    q.push({nx, ny, level, cnt, time});
                    visited[nx][ny] = true;
                }
            }
        }
        if(q.front().time == timeFlag + 1){
            timeFlag++;
            flag = true;
        }

        if(flag && !cand.empty()){ // prey candidate
            Loc prey = cand.top();
            int cnt = prey.cnt;
            int level = prey.level;
            int time = prey.time;
            for(int i = 0; i < N; i++) memset(visited[i], 0, sizeof(visited[i]));
            map[prey.x][prey.y] = 0;
            cnt++;
            if(prey.level == cnt){ // level up
                level++;
                cnt = 0;
            }
            while(!q.empty()) q.pop();
            while(!cand.empty()) cand.pop();
            q.push({prey.x, prey.y, level, cnt, time});
            visited[prey.x][prey.y] = true;
            ans = max(ans, time);
        }
        flag = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Loc start;
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            if(map[i][j] == 9){
                start = {i, j, 2, 0, 0};
                map[i][j] = 0;
            }
        }
    }

    bfs(start);
    cout << ans;
}