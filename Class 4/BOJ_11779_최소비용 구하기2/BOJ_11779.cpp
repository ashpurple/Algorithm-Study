#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321
#define SIZE 1001
using namespace std;
struct Edge{
    int v;
    int w;
    bool operator<(const Edge E) const{
        return w > E.w;
    }
};

int N, M;
int s, e;
bool visited[SIZE];
int dist[SIZE];
int path[SIZE];
vector<Edge>edge[SIZE];

void init(){
    for(int i = 1; i <= N; i++) dist[i] = INF;
}

void dijkstra(){
    priority_queue <Edge> pq;
    dist[s] = 0;
    pq.push({s, 0});

    while(!pq.empty()){
        Edge u = pq.top(); pq.pop();

        if(visited[u.v]) continue;
        visited[u.v] = true;

        for(Edge v : edge[u.v]){
            if(dist[v.v] > dist[u.v] + v.w){ // update
                dist[v.v] = dist[u.v] + v.w;
                pq.push({v.v, dist[v.v]});
                path[v.v] = u.v;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    int u, v, w;
    for(int i = 0; i < M; i++){
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
    }
    cin >> s >> e;

    init();
    dijkstra();

    vector<int> ans;
    int idx = e;
    ans.push_back(e);
    while(path[idx] != s){
        ans.push_back(path[idx]);
        idx = path[idx];
    }
    ans.push_back(s);

    /* output */
    cout << dist[e] << '\n';
    cout << ans.size() << '\n';
    while(!ans.empty()){
        cout << ans.back() << ' ';
        ans.pop_back();
    }

    return 0;
}