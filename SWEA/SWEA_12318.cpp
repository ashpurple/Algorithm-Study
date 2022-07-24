int Map[11][11];
int n;

struct Loc{
    int x;
    int y;
};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void bfs_init(int N, int map[10][10]){
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= N ; j++){
            Map[i][j] = map[i - 1][j - 1];
        }
    }
    n = N;
}

int bfs(int x1, int y1, int x2, int y2){
    int distance[11][11];
    for(int i = 0; i < 11; i++){
        for(int j = 0; j < 11; j++){
            distance[i][j] = -1;
        }
    }
    
    Loc q[100];
    int s,e;
    s = 0;
    e = 1;
    q[s] = Loc();
    q[s].x = x1;
    q[s].y = y1;
    distance[y1][x1] = 0;
    
    while(s < e){
        Loc cur = q[s++];
        if(cur.x == x2 && cur.y == y2){
            break;
        }
        for(int i = 0 ; i < 4 ; i++){
            int nx = cur.x + dx[i];
            int ny = cur.y+  dy[i];
            if(ny >= 1 && nx >= 1 && ny <= n && nx <= n && Map[ny][nx] == 0 && distance[ny][nx] == -1){
                distance[ny][nx] = distance[cur.y][cur.x] + 1;
                Loc newLoc = {nx, ny};
                q[e++] = newLoc;
            }
        }
    }
    return distance[y2][x2];
}