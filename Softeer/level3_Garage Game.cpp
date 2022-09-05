#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;
struct Loc{
	int x; int y;
};
int N;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ans;

void printVisit(bool visited[45][15]){
	for(int i = 2 * N; i < 3*N; i++){
		for(int j = 0; j < N; j++) cout << visited[i][j];
		cout<< '\n';
	}
}
void printMap(int map[45][15]){
	for(int i = 0; i < 3*N; i++){
		for(int j = 0; j < N; j++) cout << map[i][j];
		cout<< '\n';
	}
}

bool isValid(int x, int y, int newMap[45][15], int num, bool visited[15][15]){
	if(x < 2 * N || y < 0 || x >= 3 * N || y >= N) return false;
	if(visited[x][y]) return false;
	if(newMap[x][y] != num) return false;
	return true;
}

void mapCopy(int map[45][15], int newMap[45][15]){
	for(int i = 0; i < 3*N; i++){
		for(int j = 0; j < N; j++) newMap[i][j] = map[i][j];
	}
}

void visitedCopy(bool visited[45][15], bool checked[45][15]){
	for(int i = 0; i < 3 * N; i++){
		for(int j = 0; j < N; j++){
			if(checked[i][j]) visited[i][j] = true;
		}
	}
}

int bfs(int x, int y, int newMap[45][15], bool visited[45][15]){
	int minX = x; int minY = y; int maxX = x; int maxY = y;
	int car = 1;
	int num = newMap[x][y];
	queue<Loc> q;
	q.push({x, y});
	visited[x][y] = true;
	while(!q.empty()){
		Loc loc = q.front(); q.pop();
		for(int i = 0; i < 4; i++){
			int nx = loc.x + dx[i];
			int ny = loc.y + dy[i];
			if(isValid(nx, ny, newMap, num, visited)){
				q.push({nx, ny});
				visited[nx][ny] = true;
				car++;
				minX = min(minX, nx);
				maxX = max(maxX, nx);
				minY = min(minY, ny);
				maxY = max(maxY, ny);
			}
		}
	}
	int area = (maxX - minX + 1) * (maxY - minY + 1);
	return area + car;
}

void move(int map[45][15], bool visited[45][15]){
	for(int j = 0; j < N; j++){
		int cnt = 0;
		int end = 3 * N - 1;
		for(int i = end; i >= 2 * N; i--){
			if(visited[i][j]){ // empty
				cnt++;
			}
			else{ // block
				if(cnt == 0) continue;
				for(int k = end; k > i; k--){
					if(visited[k][j]){ // can swap
						swap(map[i][j], map[k][j]);
						visited[k][j] = false;
						visited[i][j] = true;
						break;
					}
				}
			}
		}
		if(cnt == 0) continue;
		end = 2 * N + cnt - 1;
		for(int i = end; i >= cnt; i--){
			map[i][j] = map[i - cnt][j];
		}
		for(int i = cnt - 1; i >= 0; i--){
			map[i][j] = 0;
		}
	}
}

void simulate(int map[45][15], int score, int cnt){
	if(cnt == 3){
		ans = max(ans, score);
		return;
	}
	bool visited[45][15];
	memset(visited, 0, sizeof(visited));

	for(int i = 2 * N; i < 3 * N; i++){
		for(int j = 0; j < N; j++){
			if(visited[i][j]) continue;
			bool checked[45][15];
			int newMap[45][15];
			memset(checked, 0, sizeof(checked));
			mapCopy(map, newMap);
			
			int nScore = bfs(i, j, map, checked);
			visitedCopy(visited, checked);

			if(cnt < 2) move(newMap, checked);
			//printVisit(checked);
			//printMap(newMap);
			//cout << '\n';
			//cout << score + nScore << '\n';
			simulate(newMap, score + nScore, cnt + 1);
		}
	}
}

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int map[45][15];
	cin >> N;

	for(int i = 0; i < 3 * N; i++){
		for(int j = 0; j < N; j++)	cin >> map[i][j];
	}

	simulate(map, 0, 0);

	cout << ans;
	return 0;
}