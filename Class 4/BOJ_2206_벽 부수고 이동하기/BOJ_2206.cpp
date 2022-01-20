#include <iostream>
#include <queue>
using namespace std;

struct Data{
    int x;
    int y;
    bool flag;
    Data(int x, int y, bool flag): x(x), y(y), flag(flag) {};
};

int matrix[1001][1001];
bool visited[1001][1001][2] = {false, }; // [][][0]: normal, :[][][1]: break wall

int N, M;
int dx[4] = {1, -1 , 0, 0};
int dy[4] = {0, 0 , 1, -1};
int dist = 1;

int bfs(){
    queue <Data> q;
    q.push(Data(0, 0, false));
    visited[0][0][0] = true;

	while(!q.empty()){
        int cycle = q.size();
        for(int i = 0; i < cycle; i++){
            int x = q.front().x;
            int y = q.front().y;
            bool flag = q.front().flag;
            q.pop();

            if(x == N - 1 && y == M - 1) return dist; // goal

            for(int j = 0; j < 4; j++){
                int nx = x + dx[j];
                int ny = y + dy[j];

                if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

                if(!flag && matrix[nx][ny] == 1){ // break wall
                    visited[nx][ny][1] = true;
                    q.push(Data(nx, ny, true));
                }

                if(matrix[nx][ny] == 0 && !visited[nx][ny][flag]){ // move
                    visited[nx][ny][flag] = true;
                    q.push(Data(nx, ny, flag));
                }
            }
        }
        
        dist++;
    }
    return -1;
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;

    string input;
    for(int i = 0; i < N; i++){
        cin >> input;
        for(int j = 0; j < M; j++){
            matrix[i][j] = input[j] - '0';
        }
    }
    cout << bfs();
}

