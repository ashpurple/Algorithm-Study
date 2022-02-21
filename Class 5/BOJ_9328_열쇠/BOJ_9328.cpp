#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct Loc{
    int x;
    int y;
};
int T, N, M, cnt;
bool key[26];
bool visited[100][100];
char map[100][100];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<Loc> q;

void init(){
    cnt = 0;
    memset(map, '*', sizeof(map));
    memset(key, 0, sizeof(key));
    memset(visited, 0, sizeof(visited));
}

bool isPossible(int x, int y){
    if(x < 0 || N <= x || y < 0 || M <= y) return false;
    if(visited[x][y]) return false;
    if(map[x][y] == '*') return false;
    if('A' <= map[x][y] && map[x][y] <= 'Z'){ // door
        if(key[map[x][y] - 65]) {
            map[x][y] = '.';
            return true; // has 
        }
        return false;
    }
    
    return true;
}

void goEntrance(){
    /* margin entrance */
    for(int i = 0; i < N; i++){
        if(isPossible(i, 0)) {q.push({i, 0}); visited[i][0] = true;}
        if(isPossible(i, M - 1)) {q.push({i, M - 1});  visited[i][M - 1] = true;}
    }
    for(int j = 0; j < M; j++){
        if(isPossible(0, j)) {q.push({0, j}); visited[0][j] = true;}
        if(isPossible(N - 1, j)) {q.push({N - 1, j}); visited[N - 1][j] = true;}
    }

}

void bfs(){
    goEntrance();

    while(!q.empty()){
        Loc loc = q.front();
        q.pop();

        if(map[loc.x][loc.y] == '$'){
            cnt++;
            map[loc.x][loc.y] = '.';
        }
        if('a' <= map[loc.x][loc.y] && map[loc.x][loc.y] <= 'z'){ // key
            key[map[loc.x][loc.y] - 97] = true;
            map[loc.x][loc.y] = '.';
            memset(visited, 0, sizeof(visited));
            visited[loc.x][loc.y] = true;
            while(!q.empty()) q.pop();
            goEntrance();
        }

        for(int i = 0; i < 4; i++){
            int x = loc.x + dx[i];
            int y = loc.y + dy[i];
            if(isPossible(x, y)){
                q.push({x, y});
                visited[x][y] = true;
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int t = 0; t < T; t++){
        cin >> N >> M;
        init();
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++)
                cin >> map[i][j];
        }
        string input;
        cin >> input;
        if(input != "0"){
            for(char c : input) key[c - 97] = true;
        }

        bfs();
        cout << cnt << '\n';
    }
}