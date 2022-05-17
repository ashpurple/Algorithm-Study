#include <iostream>
using namespace std;

int N, M;
int map[500][500];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool visited[500][500];
int ans;

bool isValid(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M) return false;
    if(visited[x][y]) return false;
	return true;
}

void dfs(int x, int y, int depth, int sum) {
	if (depth == 3) {
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (isValid(nx, ny)){
            visited[nx][ny] = true;
            dfs(nx, ny, depth + 1, sum + map[nx][ny]);
            visited[nx][ny] = false;
        }
	}
}

void shape1(int r, int c){
	int sum = 0;
	sum = map[r][c] + map[r][c + 1] + map[r][c + 2] + map[r - 1][c + 1];
	ans = max(ans, sum);
}

void shape2(int r, int c){
	int sum = 0;
	sum = map[r][c] + map[r][c + 1] + map[r][c + 2] + map[r + 1][c + 1];
	ans = max(ans, sum);
}

void shape3(int r, int c){
	int sum = 0;
	sum = map[r][c] + map[r + 1][c] + map[r + 2][c] + map[r + 1][c + 1];
	ans = max(ans, sum);
}

void shape4(int r, int c){
	int sum = 0;
	sum = map[r][c] + map[r - 1][c + 1] + map[r][c + 1] + map[r + 1][c + 1];
	ans = max(ans, sum);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = true;
			dfs(i, j, 0, map[i][j]);
			visited[i][j] = false;
			if (i - 1 >= 0 && j + 2 < M) shape1(i, j);
			if (j + 2 < M && i + 1 < N) shape2(i, j);
			if (i + 2 < N && j + 1 < M) shape3(i, j);
			if (i + 1 < N && i - 1 >= 0 && j + 1 < M) shape4(i, j);
		}
	}

	cout << ans;

	return 0;
}