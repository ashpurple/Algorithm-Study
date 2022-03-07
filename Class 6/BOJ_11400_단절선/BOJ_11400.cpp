#include <iostream>
#include <algorithm>
#include <vector>
#define SIZE 100001
using namespace std;
struct Edge{
    int u;
    int v;
    bool operator<(const Edge e)const{
        if(u == e.u) return v < e.v;
        return u < e.u; // asc
    }
};
int V, E, cnt;
int discovered[SIZE];
vector<int> edge[SIZE];
vector<Edge> cutEdge;

int dfs(int cur, int prev){
    discovered[cur] = ++cnt;
    int minNum = discovered[cur]; // earliest discovered num

    for(int next: edge[cur]){
        if(next == prev) continue; // self edge
        if(!discovered[next]){
            int nextMin = dfs(next, cur); // first visit node
            if(nextMin > discovered[cur]){ // can't go other way
                int u = min(cur, next);
                int v = max(cur, next);
                cutEdge.push_back({u, v});
            }
            minNum = min(minNum, nextMin); // update earliest num
        } 
        else minNum = min(minNum, discovered[next]);
    }
    return minNum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    int u, v;
    for(int i = 1; i <= E; i++){
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    for(int i = 1; i <= V; i++){
        if(!discovered[i]) dfs(i, 0);
    }

    /* print vertex */
    sort(cutEdge.begin(), cutEdge.end());
    cout << cutEdge.size() << '\n';

    for(Edge res: cutEdge)
        cout << res.u << ' ' << res.v << '\n';
    
    return 0;
}