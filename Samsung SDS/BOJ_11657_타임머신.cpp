#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int SIZE = 501;
const int INF = 1987654321;

struct Data {
    int u; int v; int w;
};

vector<Data> edge;
int N, M;
long long dist[SIZE];

void init(){
    for(int i = 1; i <= N; i++)
        dist[i] = INF;
}

void Bellman_Ford(int start){
    dist[start] = 0;
    for (int i = 0; i < N - 1; i++){
        for (int j = 0; j < edge.size(); j++){
            int u = edge[j].u;
            int v = edge[j].v;
            int w = edge[j].w;
 
            if (dist[u] == INF) continue;
            if (dist[v] > dist[u] + w) dist[v] = dist[u] + w;
        }
    }
 
    for (int i = 0; i < edge.size(); i++){ // 음의 사이클
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;
 
        if (dist[u] == INF) continue;
        if (dist[v] > dist[u] + w){
            cout << -1 << '\n';
            return;
        }
    }
    for(int i = 2; i <= N; i++){
        if(dist[i] == INF) cout << -1 << '\n';
        else cout << dist[i] << '\n';
    }
}

int main(){
    cin >> N;
    cin >> M;
    int u, v, w;
    init();
    for(int i = 0; i < M; i++){
        cin >> u >> v >> w;
        edge.push_back({u, v, w});
    }
    Bellman_Ford(1);
}