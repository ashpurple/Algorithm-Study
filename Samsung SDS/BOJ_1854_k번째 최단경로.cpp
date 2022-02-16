#include <iostream>
#include <vector>
#include <queue>
using namespace std;
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

int N, M, K;
vector<Edge> edge[NUM];
priority_queue<int> dist[NUM]; // descending

void dijkstra(int start){
    priority_queue<Edge> pq; // ascending
    pq.push(Edge(start, 0));
    dist[start].push(0); // default distance

    while(!pq.empty()){
        Edge u = pq.top();
        pq.pop();

        for(Edge v : edge[u.vertex]){
            if(dist[v.vertex].size() < K){
                pq.push(Edge(v.vertex, u.weight + v.weight));
                dist[v.vertex].push(u.weight + v.weight);
            }
            else if(dist[v.vertex].top() > u.weight + v.weight){
                pq.push(Edge(v.vertex, u.weight + v.weight));
                dist[v.vertex].pop();
                dist[v.vertex].push(u.weight + v.weight);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    int u, v, w;
    for(int i = 0; i < M; i++){
        cin >> u >> v >> w;
        edge[u].push_back(Edge(v, w));
    }

    dijkstra(1);

    for(int i = 1; i <= N; i++){
        if(dist[i].size() != K) cout << "-1\n";
        else cout << dist[i].top() << '\n';
    }
}