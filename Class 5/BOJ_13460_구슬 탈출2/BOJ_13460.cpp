#include <iostream>
#include <queue>
using namespace std;

struct Loc{
    int bx;
    int by;
    int rx;
    int ry;
};
int N, M, cnt;
bool visited[10][10][10][10];
char map[10][10];
bool flag;

Loc move(Loc loc, int dir){
    int nbx = loc.bx;
    int nby = loc.by;
    int nrx = loc.rx;
    int nry = loc.ry;

    if(dir == 0){ // right
        while(true){ // blue move
            nby++;
            if(map[nbx][nby] == 'O') return {-1, -1, -1, -1};
            if(map[nbx][nby] == '#') break;
        }
        nby--;
        while(true){ // red move
            nry++;
            if(map[nrx][nry] == 'O') return {0, 0, 0, 0};
            if(map[nrx][nry] == '#') break;
        }
        nry--;
        if(nbx == nrx && nby == nry){ // if same
            if(loc.by > loc.ry) nry--;
            else nby--;
        }
    }
    if(dir == 1){ // left
        while(true){ // blue move
            nby--;
            if(map[nbx][nby] == 'O') return {-1, -1, -1, -1};
            if(map[nbx][nby] == '#') break;
        }
        nby++;
        while(true){ // red move
            nry--;
            if(map[nrx][nry] == 'O') return {0, 0, 0, 0};
            if(map[nrx][nry] == '#') break;
        }
        nry++;
        if(nbx == nrx && nby == nry){ // if same
            if(loc.by > loc.ry) nby++;
            else nry++;
        }
    }
    if(dir == 2){ // up
        while(true){ // blue move
            nbx--;
            if(map[nbx][nby] == 'O') return {-1, -1, -1, -1};
            if(map[nbx][nby] == '#') break;
        }
        nbx++;
        while(true){ // red move
            nrx--;
            if(map[nrx][nry] == 'O') return {0, 0, 0, 0};
            if(map[nrx][nry] == '#') break;
        }
        nrx++;
        if(nbx == nrx && nby == nry){ // if same
            if(loc.bx > loc.rx) nbx++;
            else nrx++;
        }
    }
    if(dir == 3){ // down
        while(true){ // blue move
            nbx++;
            if(map[nbx][nby] == 'O') return {-1, -1, -1, -1};
            if(map[nbx][nby] == '#') break;
        }
        nbx--;
        while(true){ // red move
            nrx++;
            if(map[nrx][nry] == 'O') return {0, 0, 0, 0};
            if(map[nrx][nry] == '#') break;
        }
        nrx--;
        if(nbx == nrx && nby == nry){ // if same
            if(loc.bx > loc.rx) nrx--;
            else nbx--;
        }
    }
    if(loc.bx == nbx && loc.by == nby && loc.rx == nrx && loc.ry == nry)
        return {-1, -1, -1, -1};
    return {nbx, nby, nrx, nry};
}

void bfs(int a, int b, int c, int d){
    queue<Loc> q;
    q.push({a, b, c, d}); // initial

    while(!q.empty()){
        int cycle = q.size();
        cnt++;
        if(cnt > 10) return;
        for(int c = 0; c < cycle; c++){
            Loc loc = q.front();
            q.pop();

            for(int i = 0; i < 4; i++){
                Loc nLoc = move(loc, i);
                int bx = nLoc.bx;
                int by = nLoc.by;
                int rx = nLoc.rx;
                int ry = nLoc.ry;
                
                if(bx == -1) continue; // fail
                if(bx == 0){// success
                    flag = true;
                    return;
                }
                if(visited[bx][by][rx][ry]) continue; // visited
                
                q.push({bx, by, rx, ry});
                visited[bx][by][rx][ry] = true;
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    int bx, by, rx, ry;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> map[i][j];
            if(map[i][j] == 'B'){
                bx = i;
                by = j;
                map[i][j] = '.';
            }
            if(map[i][j] == 'R'){
                rx = i;
                ry = j;
                map[i][j] = '.';
            }
        }
    }
    bfs(bx, by, rx, ry);
    if(flag) cout << cnt << '\n';
    else cout << -1;
}