#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;
#define INF INT_MAX
#define NUM 1001

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
int N, M, X;
vector<Edge> edge[NUM];
vector<Edge> r_edge[NUM];
int dist[NUM];
int goDist[NUM];

void init(){
    for(int i = 0; i <= N; i++)
        dist[i] = INF;
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
            }
        }
    }
}

void r_dijkstra(int start){
    init();
    priority_queue<Edge> pq;
    pq.push(Edge(start, 0));
    dist[start] = 0;

    while(!pq.empty()){
        Edge u = pq.top();
        pq.pop();

        if(u.weight > dist[u.vertex]) continue;

        for(int i = 0; i < r_edge[u.vertex].size(); i++){
            Edge v = r_edge[u.vertex][i];

            if(dist[v.vertex] > dist[u.vertex] + v.weight){
                dist[v.vertex] = dist[u.vertex] + v.weight;
                pq.push(Edge(v.vertex, dist[v.vertex]));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> X;
    int u, v, w;
    for(int i = 0; i < M; i++){
        cin >> u >> v >> w;
        edge[u].push_back(Edge(v, w));
        r_edge[v].push_back(Edge(u, w));
    }

    r_dijkstra(X);
    for(int i = 1; i <= N; i++){
        goDist[i] = dist[i];
    }

    dijkstra(X);
    int ans = 0;
    for(int i = 1; i <= N; i++){
        goDist[i] += dist[i];
        ans = max(ans, goDist[i]);
    }
    cout << ans;  
}