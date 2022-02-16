#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
#define INF 987654321
#define NUM 501

struct Edge{
    int vertex;
    int weight;
    Edge(int v, int w){
        vertex = v;
        weight = w;
    }
    bool operator<(const Edge e)const{
        return weight > e.weight;
    }
};
int N, M, S, D;
vector<Edge> edge[NUM];
vector<int> path[NUM];
int dist[NUM];
bool visited[NUM];

void init(){
    for(int i = 0; i < N; i++){
        dist[i] = INF;
        visited[i] = false;
    }
}

void dijkstra(int start){
    init();
    priority_queue<Edge> pq;
    pq.push(Edge(start, 0));
    dist[start] = 0;

    while(!pq.empty()){
        Edge u = pq.top();
        pq.pop();

        if(u.weight > dist[u.vertex]) continue;

        for(int i = 0; i < edge[u.vertex].size(); i++){
            Edge v = edge[u.vertex][i];

            if(dist[v.vertex] > dist[u.vertex] + v.weight){
                dist[v.vertex] = dist[u.vertex] + v.weight;
                pq.push(Edge(v.vertex, dist[v.vertex]));
                path[v.vertex].clear();
                path[v.vertex].push_back(u.vertex);
            }
            else if(dist[v.vertex] == dist[u.vertex] + v.weight){
                path[v.vertex].push_back(u.vertex);
            }
        }
    }
}

void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int prev : path[cur]){
            for(int i = 0; i < edge[prev].size(); i++){
                if(edge[prev][i].vertex == cur){ // remove
                    edge[prev][i].weight = INF;
                    
                    if(!visited[prev]){
                        q.push(prev);
                        visited[prev] = true;
                    }
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        cin >> N >> M;
        if(N == 0 && M == 0) break;
        cin >> S >> D;
        int u, v, w;

        for(int i = 0; i < NUM; i++){
            edge[i].clear();
            path[i].clear();
        } 
        for(int i = 0; i < M; i++){
            cin >> u >> v >> w;
            edge[u].push_back(Edge(v, w));
        }
        dijkstra(S);
        bfs(D);
        dijkstra(S);

        if(dist[D] == INF) cout << "-1\n";
        else cout << dist[D] << '\n';
    }
}