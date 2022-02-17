#include <iostream>
#include <vector>
#include <algorithm>
#define NUM 1001
using namespace std;

struct Edge{
    int u;
    int v;
    int w;
    bool operator<(const Edge e) const{
        return w < e.w;
    }
};
int N, M;
int sum;
int root[NUM];
vector<Edge> edge;

int find(int x){
    if(root[x] == x) return x;
    else return root[x] = find(root[x]);
}
void Union(int x, int y){
    x = find(x);
    y = find(y);
    root[x] = y;
}

bool isCycle(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return true;
    else return false;
}

void kruskal(){
    for(Edge e: edge){
        if(isCycle(e.u, e.v)) continue;
        sum += e.w;
        Union(e.u, e.v);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int u, v, w;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> u >> v >> w;
        edge.push_back({u, v, w});
    }

    for(int i = 1; i <= N; i++) root[i] = i;
    sort(edge.begin(), edge.end());
    
    kruskal();
    cout << sum;
}