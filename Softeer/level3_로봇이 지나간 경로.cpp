#include<iostream>
#include<string.h>
#include<vector>
#include<string>
using namespace std;
struct Point{
	int x, y;
};
int H, W;
char map[25][25];
bool visited[25][25];
int dir;
int dx[4]={1, 0, -1, 0};
int dy[4]={0, 1, 0, -1};
vector<Point> road;
Point start;
string order;

bool isValid(int x, int y){
	if(x < 0 || y < 0 || x >= H || y >= W) return false;
	return true;
}

void backtracking(Point s, int d, string str, int x, int y, int cnt, int next){
	if(cnt == road.size()){
		if(order.size() > str.size() || order.size() == 0){
			order = str;
			start = s;
			dir = d;
		}
		return;
	}

	int nx1, ny1, nx2, ny2;
	int nd;
	string c;
	for(int i = 0; i < 4; i++){
		nd = (next + i) % 4;
		nx1 = x + dx[nd];
		ny1 = y + dy[nd];
		nx2 = x + dx[nd] * 2;
		ny2 = y + dy[nd] * 2;
		if(!isValid(nx2, ny2)) continue;
		if(!visited[nx2][ny2] && !visited[nx1][ny1] && map[nx1][ny1] == '#' && map[nx2][ny2] == '#'){
			if(i == 0) c = "A";
			if(i == 1) c = "LA";
			if(i == 2) c = "LLA";
			if(i == 3) c = "RA";
			visited[nx1][ny1] = true;
			visited[nx2][ny2] = true;
			backtracking(s, d, str + c, nx2, ny2, cnt + 2, nd);
			visited[nx1][ny1] = false;
			visited[nx2][ny2] = false;
		}
		
	}
}
int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> H >> W;

	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			cin >> map[i][j];
			if(map[i][j] == '#')
				road.push_back({i, j});
		}
	}

	for(Point p: road){
		Point s = p;
		memset(visited, false, sizeof(visited));
		visited[s.x][s.y] = true;
		for(int i = 0; i < 4; i++){
			backtracking(s, i, "", p.x, p.y, 1, i);
		}
	}

	cout<< start.x + 1<< ' ' << start.y + 1 << '\n';
	if(dir == 0) cout<<'v'<< '\n';
	if(dir == 1) cout<<'>'<< '\n';
	if(dir == 2) cout<<'^'<< '\n';
	if(dir == 3) cout<<'<'<< '\n';
	cout << order;
	return 0;
}