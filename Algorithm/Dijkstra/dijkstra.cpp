#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321
#define SIZE 100001 // Vertex + 1

vector<Data> edge[SIZE]; // 2 dimension
priority_queue<Data> pq;
int dist[SIZE];
bool isVisited[SIZE];

int V, E;
int u, v, w;

struct Data {
    int vertex;
    int weight;
    Data() {};
    Data(int vertex, int weight) : vertex(vertex), weight(weight) {};
    bool operator<(const Data d) const {
        return weight > d.weight; // ascending
    }
};

void init(){
   for (int i = 0; i <= V; i++) {
        edge[i].clear();
        dist[i] = INF;
        isVisited[i] = false;
    }    
}

void dijkstra(int start){
    dist[start] = 0; 
    pq.push(Data(start, 0)); // start vertex

    while (!pq.empty()) {
        Data u = pq.top();
        pq.pop();

        if (isVisited[u.vertex]) continue;
        isVisited[u.vertex] = true;

        for (int i = 0; i < edge[u.vertex].size(); i++) {
            Data v = edge[u.vertex].at(i);
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
    
    int start;
    cin >> start;
    
    init();

    /* input */
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        edge[u].push_back(Data(v, w));
        //v[v].push_back(Data(u, w)); // bidirectional
    }

    dijkstra(start);

    /* output (1 to V) */ 
    for (int i = 1; i <= V; i++) {
        if(dist[i] == INF)
            cout << "INF" << '\n';
        else
            cout << dist[i] << '\n';
    }
}