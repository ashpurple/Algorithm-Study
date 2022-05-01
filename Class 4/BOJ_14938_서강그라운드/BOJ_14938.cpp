#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 100000;
const int SIZE = 101;

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

int dist[SIZE];
bool visited[SIZE];
int V, E;
int u, v, w;

void init(){
   for (int i = 1; i <= V; i++) {
        dist[i] = INF;
        visited[i] = false;
   }
}

void dijkstra(int start){
    init();
    priority_queue<Data> pq;
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

    int range;
    int item[101];

    cin >> V >> range >> E;
    for(int i = 1; i <= V; i++){
        cin >> item[i];
    }
    
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        edge[u].push_back(Data(v, w));
        edge[v].push_back(Data(u, w));
    }

    int ans = 0;
    for(int i = 1; i <= V; i++){
        int itemCnt = 0;
        dijkstra(i);
        for(int j = 1; j <= V; j++){
            if(dist[j] <= range)
                itemCnt += item[j];
        }
        ans = max(ans, itemCnt);
    }
    cout << ans;
}