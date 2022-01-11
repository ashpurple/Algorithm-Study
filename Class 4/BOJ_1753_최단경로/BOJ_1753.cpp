#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321

struct Data {
    int node;
    int weight;
    Data() {};
    Data(int node, int weight) : node(node), weight(weight) {};
    bool operator<(const Data d) const {
        return weight > d.weight;
    }
};

vector<Data> edge[20001];
int dist[20001];
bool isVisited[20001];
priority_queue<Data> pq;

int V, E;
int u, v, w;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;

    for (int i = 0; i <= V; i++) {
        edge[i].clear();
        dist[i] = INF;
        isVisited[i] = false;
    }

    int start;
    cin >> start;
    dist[start] = 0; 
    pq.push(Data(start, 0)); // start node

    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        edge[u].push_back(Data(v, w));
        //v[v].push_back(Data(u, w)); // 양방향
    }

    while (!pq.empty()) {
        Data now = pq.top();
        pq.pop();

        if (isVisited[now.node]) continue;
        isVisited[now.node] = true;

        for (int i = 0; i < edge[now.node].size(); i++) {
            Data next = edge[now.node].at(i);
            if(dist[next.node] > dist[now.node] + next.weight){
                dist[next.node] = dist[now.node] + next.weight;
                pq.push(Data(next.node, dist[next.node]));
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if(dist[i] == INF)
            cout << "INF" << '\n';
        else
            cout << dist[i] << '\n';
    }
}