#include <iostream>
#include <queue>
using namespace std;
struct Loc{
    int x;
    int y;
    int cnt;
};
int T, N, M, R, K;
char map[100][100];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool visited[100][100];
bool king;
int ans;
int sX, sY;

void init(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            visited[i][j] = false;
        }
    }
}

bool isValid(int x, int y){
    if(x < 0 || y < 0 || x >= N || y >= M) return false;
    if(visited[x][y]) return false;
    if(map[x][y] == 'X') return false;
    return true;
}

Loc bfs(Loc start, char target){
    init();
    queue <Loc> q;
    q.push(start);
    visited[start.x][start.y] = true;

    while(!q.empty()){
        Loc loc = q.front(); q.pop();
        int x = loc.x; int y = loc.y;

        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(isValid(nx, ny)){
                Loc nLoc = {nx, ny, loc.cnt + 1};
                if(map[nx][ny] == target){
                    return nLoc;
                }
                q.push(nLoc);
                visited[nx][ny] = true;
            }
        }
    }
}

char arr[3] = {'A', 'B', 'C'};
bool visited2[3];
void dfs(int num, Loc loc) { // nPm
	if (num == 3) {
        int cnt = loc.cnt;
        cnt += abs(loc.x - sX) + abs(loc.y - sY);
        ans = min(ans, cnt);
        return;
	}
	for (int i = 0; i < 3; i++) {
		if (!visited2[i]) {
			visited2[i] = true;
			dfs(num + 1, bfs(loc, arr[i]));
			visited2[i] = false;
		}
	}
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int t = 1; t <= T; t++){
        cin >> N >> M >> R >> K;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin >> map[i][j];
                if(map[i][j] == 'S'){
                    sX = i; sY = j;
                }
            }
        }
        Loc start = {R - 1, K - 1, 0};
        ans = 1987654321;
        dfs(0, start);
        cout << '#' << t << ' ' << ans << '\n';
    }
}