#include <iostream>
#include <queue>
using namespace std;

void bfs();

int matrix[1000][1000];
bool visited[1000][1000];
queue <pair<int, int>> q;
int M, N;
int unripeCnt = 0, ripeCnt = 0, day = -1;
int dx[4] = {1, -1 , 0, 0};
int dy[4] = {0, 0 , 1, -1};

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> M >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> matrix[i][j];
            if(matrix[i][j] == 1){
                q.push(make_pair(i,j));
                visited[i][j] = true;
            }
            else if(matrix[i][j] == 0)
                unripeCnt++;
        }
    }

    bfs();

    if(ripeCnt != unripeCnt)
        day = -1;
    else if(unripeCnt == 0)
        day = 0;

    cout << day << '\n';
    
}

void bfs(){
	while(!q.empty()){
        int cycle = q.size();

        for(int i = 0; i < cycle; i++){
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            for(int j = 0; j < 4; j++){
                int nx = x + dx[j];
                int ny = y + dy[j];

                if(nx < 0 || nx >= N || ny < 0 || ny >= M) 
                    continue;

                if(matrix[nx][ny] == 0 && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    ripeCnt++;
                    q.push(make_pair(nx, ny));
                }
            }
        }
        day++;
    }
}