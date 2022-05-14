#include <iostream>
using namespace std;

struct Loc{
    int x;
    int y;
};
struct Pipe{
    Loc a;
    Loc b;
    int status; // 0 가로 1 세로 2 대각선
};

int N, cnt;
bool map[16][16];

bool isValid(Pipe pipe){
    Loc loc = pipe.b;
    if(loc.x >= N || loc.y >= N) return false;
    if(map[loc.x][loc.y]) return false;
    if(pipe.status == 2){
        if(map[loc.x - 1][loc.y] || map[loc.x][loc.y - 1]) return false;
    }
    return true;
}

void simulate(Pipe pipe){
    if(pipe.b.x == N - 1 && pipe.b.y == N - 1){
        cnt++;
        return;
    }

    Pipe movePipe;
    if(pipe.status == 0){
        movePipe = {{pipe.b.x, pipe.b.y}, {pipe.b.x, pipe.b.y + 1}, 0};
        if(isValid(movePipe)) simulate(movePipe);
        movePipe = {{pipe.b.x, pipe.b.y}, {pipe.b.x + 1, pipe.b.y + 1}, 2};
        if(isValid(movePipe)) simulate(movePipe);
    }
    else if(pipe.status == 1){
        movePipe = {{pipe.b.x, pipe.b.y}, {pipe.b.x + 1, pipe.b.y}, 1};
        if(isValid(movePipe)) simulate(movePipe);
        movePipe = {{pipe.b.x, pipe.b.y}, {pipe.b.x + 1, pipe.b.y + 1}, 2};
        if(isValid(movePipe)) simulate(movePipe);
    }
    else if(pipe.status == 2){
        movePipe = {{pipe.b.x, pipe.b.y}, {pipe.b.x, pipe.b.y + 1}, 0};
        if(isValid(movePipe)) simulate(movePipe);
        movePipe = {{pipe.b.x, pipe.b.y}, {pipe.b.x + 1, pipe.b.y}, 1};
        if(isValid(movePipe)) simulate(movePipe);
        movePipe = {{pipe.b.x, pipe.b.y}, {pipe.b.x + 1, pipe.b.y + 1}, 2};
        if(isValid(movePipe)) simulate(movePipe);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            cin >> map[i][j];
    }

    Pipe pipe = {{0, 0}, {0, 1}, 0};
    simulate(pipe);
    cout << cnt;
}