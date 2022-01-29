#include <iostream>
#include <algorithm>
#include <vector>
#define vertexNum 10000
using namespace std;

struct Edge{
    int u;
    int v;
    int w;

    bool operator<(const Edge e) const {
        return w < e.w; // ascending
    }
};

vector <Edge> edge;
int root[vertexNum + 1];
int V, E;

int find(int x){
    if(root[x] == x) return x;
    return root[x] = find(root[x]);
}

void Union(int x, int y){
    x = find(x);
    y = find(y);
    root[y] = x;
}

bool isCycle(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return true;
    return false;
}

int kruskal(){
    int sum = 0;
    for(int i = 0; i < edge.size(); i++){
        if(!isCycle(edge[i].u, edge[i].v)){
            sum += edge[i].w;
            Union(edge[i].u, edge[i].v);
        }
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    int u, v, w;

    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        edge.push_back({u, v, w});
    }
    for(int i = 1; i <= V; i++) root[i] = i;

    sort(edge.begin(), edge.end());
    
    cout << kruskal();
}