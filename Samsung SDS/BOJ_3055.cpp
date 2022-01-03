#include <iostream>
#include <queue>
using namespace std;

void bfs();

char map[50][50];
bool visited[50][50];
queue <pair<int, int>> S;
queue <pair<int, int>> W;
queue <pair<int, int>> D;
int M, N;
int dx[4] = {1, -1 , 0, 0};
int dy[4] = {0, 0 , 1, -1};

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
            if(map[i][j] == 'S'){
                S.push(make_pair(i,j));
                visited[i][j] = true;
            }
            else if(map[i][j] == '*'){
                W.push(make_pair(i,j));
            }
            else if(map[i][j] == 'D'){
                D.push(make_pair(i,j));
            }
        }
    }
    bfs();
}

void waterFlow(){
    int cycle = W.size();
       
    for(int i = 0; i < cycle; i++){
        int x = W.front().first;
        int y = W.front().second;
        W.pop();

        for(int j = 0; j < 4; j++){
            int nx = x + dx[j];
            int ny = y + dy[j];
            if(nx < 0 || nx >= N || ny < 0 || ny >= M) 
                continue;
            if(map[nx][ny] == '.'){
                map[nx][ny] = '*';
                W.push(make_pair(nx, ny));
            }
        }
    }    
}

void bfs(){
    int time = 0;
    bool flag = false;

	while(!S.empty()){
        time++;
        waterFlow();

        int cycle = S.size();
       
        for(int i = 0; i < cycle; i++){
            int x = S.front().first;
            int y = S.front().second;
            S.pop();
            
            for(int j = 0; j < 4; j++){
                int nx = x + dx[j];
                int ny = y + dy[j];
                if(map[nx][ny] == 'D'){
                    flag = true;
                    cout << time << '\n';
                    break;
                }
                if(nx < 0 || nx >= N || ny < 0 || ny >= M) 
                    continue;
                if(map[nx][ny] == '*' || map[nx][ny] == 'X' || map[nx][ny] == 'S')
                    continue;
                if(map[nx][ny] == '.' && !visited[nx][ny]){
                    visited[nx][ny] = true;
                    S.push(make_pair(nx, ny));
                }
            }
            if(flag)
                break;
        }
        if(flag)
            break;
    }
    if(!flag)
        cout << "KAKTUS" << '\n';
}