#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct Loc{
    int x;
    int y;
};
int N;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool map[25][25];
bool visited[25][25];

bool isValid(int x, int y){
    if(x < 0 || x >= N || y < 0 || y >= N) return false;
    if(visited[x][y]) return false;
    if(!map[x][y]) return false;
    return true;
}

int bfs(int x, int y){
    queue<Loc> q;
    q.push({x, y});
    visited[x][y] = true;
    int cnt = 1;

    while(!q.empty()){
        Loc loc = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            int nx = loc.x + dx[i];
            int ny = loc.y + dy[i];
            if(isValid(nx, ny)){
                q.push({nx, ny});
                visited[nx][ny] = true;
                cnt++;
            }
        }
    }
    return cnt;
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int u, v;
    for(int i = 0; i < N; i++){
        string input;
        cin >> input;
        for(int j = 0; j < N; j++)
            map[i][j] = input[j] - '0';
    }
    vector<int> res;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(map[i][j] && !visited[i][j]){
                res.push_back(bfs(i, j));
            }
        }
    }

    cout << res.size() << '\n';
    sort(res.begin(), res.end());
    for(int cnt: res) cout << cnt << '\n';
}