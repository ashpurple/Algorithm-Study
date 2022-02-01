#include <iostream>
#include <vector>
#include <queue>
#define SIZE 1001
#define MAX 987654321
using namespace std;

int T, N, K, W;
vector<int> building[SIZE];
int inDegree[SIZE];
int cost[SIZE];
int dist[SIZE];

void init(){
    for(int i = 1; i <= N; i++){
        building[i].clear();
        inDegree[i] = 0;
        dist[i] = 0;
    }
}

void topologySort(){
    queue<int> q;

    for(int i = 1; i <= N; i++){
        if(inDegree[i] == 0) {
            q.push(i);
            dist[i] = cost[i];
        }
    }

    while(!q.empty()){
        int cycle = q.size();

        for(int i = 0; i < cycle; i++){
            int u = q.front(); q.pop();

            if(u == W) // target
                return;
            
            for(int v: building[u]){
                if(--inDegree[v] == 0) q.push(v);
                if(dist[v] < dist[u] + cost[v]) // dp
                    dist[v] = dist[u] + cost[v];
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int t = 0; t < T; t++){
        cin >> N >> K;
        init();
        for(int i = 1; i <= N; i++) cin >> cost[i];

        int u, v;
        for(int i = 0; i < K; i++){
            cin >> u >> v;
            building[u].push_back(v);
            inDegree[v]++;
        }

        cin >> W;
        topologySort();
        cout << dist[W] << '\n';
    }
}