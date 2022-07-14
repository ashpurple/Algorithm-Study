#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 987654321;
const int SIZE = 501; // Vertex + 1
struct Data {
    int vertex;
    int weight;
    bool operator<(const Data d) const {
        return weight > d.weight; // ascending
    }
};

vector<Data> edge[SIZE];
vector<Data> r_edge[SIZE];
int dist[SIZE];
bool visited[SIZE];
int V, E;

void init(){
   for (int i = 1; i <= V; i++) {
        dist[i] = INF;
        visited[i] = false;
    }    
}

int dijkstra(int start){
    priority_queue<Data> pq;
    dist[start] = 0; 
    pq.push({start, 0}); // start vertex

    while (!pq.empty()) {
        Data u = pq.top();
        pq.pop();
        if (visited[u.vertex]) continue;
        visited[u.vertex] = true;

        for(Data v : edge[u.vertex]){
            if(dist[v.vertex] > dist[u.vertex] + v.weight){
                dist[v.vertex] = dist[u.vertex] + v.weight;
                pq.push({v.vertex, dist[v.vertex]});
            }
        }
    }
    int cnt = 0;
    for(int i = 1; i <= V; i++){
        if(dist[i] != INF) cnt++;
    }
    return cnt;
}
int r_dijkstra(int start){
    priority_queue<Data> pq;
    dist[start] = 0; 
    pq.push({start, 0}); // start vertex

    while (!pq.empty()) {
        Data u = pq.top();
        pq.pop();

        if (visited[u.vertex]) continue;
        visited[u.vertex] = true;

        for(Data v : r_edge[u.vertex]){
            if(dist[v.vertex] > dist[u.vertex] + v.weight){
                dist[v.vertex] = dist[u.vertex] + v.weight;
                pq.push({v.vertex, dist[v.vertex]});
            }
        }
    }
    int cnt = 0;
    for(int i = 1; i <= V; i++){
        if(dist[i] != INF) cnt++;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    
    
    int u, v, w;
    for (int i = 0; i < E; i++) {
        cin >> u >> v;
        edge[u].push_back({v, 1});
        r_edge[v].push_back({u, 1});
    }

    int ans = 0;
    for(int i = 1; i <= V; i++){
        init();
        int a = dijkstra(i);
        init();
        int b = r_dijkstra(i);
        if(a + b == V + 1) ans++;
    }
    cout << ans;
}