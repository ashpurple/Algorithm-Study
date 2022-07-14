#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 1000; // vertex num
const int INF = 987654321;

struct Edge {
    int u; int v; int w;
};

vector<Edge> edge; // 2 dimension
int N, M; // vetex, edge
int dist[SIZE];

void init(){
    for(int i = 1; i <= N; i++) dist[i] = INF;
}

void Bellman_Ford(int start){
    dist[start] = 0;
    for (int i = 0; i < N - 1; i++){
        for (Edge edge : edge){
            int u = edge.u;
            int v = edge.v;
            int w = edge.w;
 
            if (dist[u] == INF) continue;
            if (dist[v] > dist[u] + w) dist[v] = dist[u] + w;
        }
    }
 
     for (Edge edge : edge){ // 음의 사이클
        int u = edge.u;
        int v = edge.v;
        int w = edge.w;
 
        if (dist[u] == INF) continue;
        if (dist[v] > dist[u] + w){
            cout << "Negative Cycle" << '\n';
            return;
        }
    }
    for(int i = 1; i <= N; i++) cout << dist[i] << '\n';
}

int main(){
    cin >> N; // vertex num
    cin >> M; // edge num
    int u, v, w;
    init();
    for(int i = 0; i < M; i++){
        cin >> u >> v >> w;
        edge.push_back({u, v, w});
    }
}