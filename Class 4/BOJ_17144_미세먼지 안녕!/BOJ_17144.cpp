#include <iostream>
using namespace std;
int R, C, T;
int map[50][50];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool isValid(int x, int y){
    if(x < 0 || y < 0 || x >= R || y >= C) return false;
    if(map[x][y] == -1) return false;

    return true;
}

void dust(){
    int newMap[50][50];
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            newMap[i][j] = 0;
        }
    }
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(map[i][j] >= 5){
                int cnt = 0;
                int amount = map[i][j] / 5;
                for(int dir = 0; dir < 4; dir++){
                    int nx = i + dx[dir];
                    int ny = j + dy[dir];
                    if(isValid(nx, ny)){
                        newMap[nx][ny] += amount;
                        cnt++;
                    }
                }
                newMap[i][j] += (map[i][j] - ((map[i][j] / 5) * cnt));
            }
            else{
                newMap[i][j] += map[i][j];
            }
        }
    }

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            map[i][j] = newMap[i][j];
        }
    }
}

void clean(int up, int down){
    for (int i = up - 1; i > 0; i--)
        map[i][0] = map[i - 1][0];
    for (int i = 0; i < C - 1; i++)
        map[0][i] = map[0][i + 1];
    for (int i = 1; i <= up; i++)
        map[i - 1][C - 1] = map[i][C - 1];
    for (int i = C - 1; i > 1; i--)
        map[up][i] = map[up][i - 1];
    map[up][1] = 0;

    for (int i = down + 1; i < R - 1; i++)
        map[i][0] = map[i + 1][0];
    for (int i = 0; i < C - 1; i++)
        map[R - 1][i] = map[R - 1][i + 1];
    for (int i = R - 1; i >= down; i--)
        map[i][C - 1] = map[i - 1][C - 1];
    for (int i = C - 1; i > 1; i--)
        map[down][i] = map[down][i - 1];
    map[down][1] = 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int cleaner[2];
    int idx = 0;
    cin >> R >> C >> T;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> map[i][j];
            if(map[i][j] == -1) cleaner[idx++] = i;
        }
    }
    
    for(int i = 0; i < T; i++){
        dust();
        clean(cleaner[0], cleaner[1]);
    }

    int ans = 0;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(map[i][j] == -1) continue;
            ans += map[i][j];
        }
    }
    cout << ans;
}