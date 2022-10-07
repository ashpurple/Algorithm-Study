#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Loc{
    int x; int y; bool visited;
};
int T, N;
vector<Loc> conv;

bool bfs(int sx, int sy, int ex, int ey){
    queue<Loc> q;
    q.push({sx, sy, true});

    while(!q.empty()){
        Loc loc = q.front(); q.pop();
        int endDist = abs(ex - loc.x) + abs(ey - loc.y);
        if(endDist <= 1000) return true; 

        for(int i = 0; i < N; i++){
            if(conv[i].visited) continue;
            int dist = abs(loc.x - conv[i].x) + abs(loc.y - conv[i].y);
            if(dist > 1000) continue;
            q.push({conv[i].x, conv[i].y, true});
            conv[i].visited = true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int t = 0; t < T; t++){
        conv.clear();
        cin >> N;
        int sx, sy, ex, ey;
        cin >> sx >> sy;
        for(int i = 0; i < N; i++){
            int x, y;
            cin >> x >> y;
            conv.push_back({x, y, false});
        }
        cin >> ex >> ey;
        if(bfs(sx, sy, ex, ey)) cout << "happy" << '\n';
        else cout << "sad" << '\n';
    }

}