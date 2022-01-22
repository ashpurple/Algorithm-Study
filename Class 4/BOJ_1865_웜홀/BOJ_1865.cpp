#include <iostream>
#include <vector>
using namespace std;
#define SIZE 501 // vertex num
#define INF 987654321

struct Data {
    int u;
    int v;
    int w;
    Data(int u, int v, int w) :u(u), v(v), w(w) {};
};

vector<Data> edge; // 2 dimension
int T, N, M, W; // vetex, edge
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
 
            if (dist[v] > dist[u] + w) 
                dist[v] = dist[u] + w;
        }
    }
 
    for (int i = 0; i < edge.size(); i++){ // 음의 사이클
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].w;
 
        if (dist[v] > dist[u] + w){
            cout << "YES" << '\n';
            return;
        }
    }
    cout << "NO" << '\n';
}

int main(){
    cin >> T;
    for(int t = 0; t < T; t++){
        cin >> N >> M >> W;
        init();
        for(int i = 0; i < M; i++){
            int u, v, w;
            cin >> u >> v >> w;
            edge.push_back(Data(u, v, w));
            edge.push_back(Data(v, u, w));
        }
        for(int i = 0; i < W; i++){
            int u, v, w;
            cin >> u >> v >> w;
            edge.push_back(Data(u, v, -w));
        }
        
        Bellman_Ford(1);
    }
}