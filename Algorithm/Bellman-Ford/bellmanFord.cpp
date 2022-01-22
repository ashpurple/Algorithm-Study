#include <iostream>
#include <vector>
using namespace std;
#define SIZE 1000 // vertex num
#define INF 987654321

struct Data {
    int u;
    int v;
    int w;
    Data(int u, int v, int w) :u(u), v(v), w(w) {};
};

vector<Data> edge; // 2 dimension
int N, M; // vetex, edge
int dist[SIZE];

void init(){
    for(int i = 1; i <= N; i++)
        dist[i] = INF;
    vector<Data>().swap(edge);
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
            cout << "Negative Cycle" << '\n';
            return;
        }
    }
    cout << "No Negative Cycle" << '\n';
}

int main(){
    cin >> N; // vertex num
    cin >> M; // edge num
    int u, v, w;
    init();
    for(int i = 0; i < M; i++){
        cin >> u >> v >> w;
        edge.push_back(Data(u, v, w));
    }
}