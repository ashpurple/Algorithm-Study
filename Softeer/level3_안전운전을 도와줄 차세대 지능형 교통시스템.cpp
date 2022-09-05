#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
struct Point{
	int y, x, d;
};
vector<int> signals[13] = { 
	{},
    {0,1,3},{1,0,2},{2,1,3},{3,0,2},
    {0,1},{1,2},{2,3},{3,0},
    {0,3},{1,0},{2,1},{3,2}
};
int N, T;
int map[100][100][4];
bool visited[100][100][4][4];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
set<pair<int,int>> ans;

bool isValid(int nx, int ny, int t, int k){
	if(ny < 0 || nx < 0 || ny >= N || nx >= N) return false;
	if(visited[ny][nx][t % 4][k]) return false;
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> T;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            for(int k = 0; k < 4; k++)
                cin >> map[i][j][k];

    queue<Point> q;
    q.push({0, 0, 1});
    visited[0][0][0][1] = true;
    ans.insert({0,0});

    int t = 0;
    while(!q.empty()){
        int qSize = q.size();
        if(t == T) break;
        while(qSize--){
            Point point = q.front(); q.pop();
			int x = point.x;
			int y = point.y;
			int d = point.d;

            if(signals[map[y][x][t % 4]][0] != d) continue;

            for(int k : signals[map[y][x][t % 4]]){
				int nx = x + dx[k];
                int ny = y + dy[k];
                if(!isValid(nx, ny, t, k)) continue;
                visited[ny][nx][t % 4][k] = true;
                q.push({ny, nx, k});
                ans.insert({ny, nx});
            }
        }
        t++;
    }
    cout << ans.size();
}