#include <iostream>
#include <memory.h>
using namespace std;

void dfs(int, int);

bool matrix[52][52]; // padding
bool visited[52][52];
int dx[4] = {1, -1 , 0, 0};
int dy[4] = {0, 0 , 1, -1};

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    
    for(int t = 0; t < T; t++){
        memset(matrix, 0, sizeof(matrix));
        memset(visited, 0, sizeof(visited));

        int M, N, K;
        cin >> M >> N >> K;

        for(int i = 0; i < K; i++){
            int x, y;
            cin >> x >> y;
            matrix[x + 1][y + 1] = true;
        }

        int cnt = 0;
        for(int i = 1; i <= M; i++){
            for(int j = 1; j <= N; j++){
                if(!visited[i][j] && matrix[i][j]){
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}

void dfs(int x, int y){
	visited[x][y] = true;

	for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

		if(!visited[nx][ny] && matrix[nx][ny]){
            dfs(nx, ny);
        }
	}
}