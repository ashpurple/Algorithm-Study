#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 987654321;
const int SIZE = 100001;

struct Data {
    int vertex;
    int weight;
    Data() {};
    Data(int vertex, int weight) : vertex(vertex), weight(weight) {};
    bool operator<(const Data d) const {
        return weight > d.weight;
    }
};

vector<Data> edge[SIZE];
priority_queue<Data> pq;
int dist[SIZE];
bool visited[SIZE];
int V, E;
int u, v, w;

void init(){
   for (int i = 1; i <= V; i++) {
        dist[i] = INF;
    }    
}

void dijkstra(int start){
    dist[start] = 0; 
    pq.push(Data(start, 0));

    while (!pq.empty()) {
        Data u = pq.top();
        pq.pop();

        if (visited[u.vertex]) continue;
        visited[u.vertex] = true;

        for(Data v : edge[u.vertex]){
            if(dist[v.vertex] > dist[u.vertex] + v.weight){
                dist[v.vertex] = dist[u.vertex] + v.weight;
                pq.push(Data(v.vertex, dist[v.vertex]));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    
    init();

    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        edge[u].push_back(Data(v, w));
    }

    int start, end;
    cin >> start >> end;
    dijkstra(start);

    cout << dist[end];
}