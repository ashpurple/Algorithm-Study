#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M, V;
bool visited[1001];
vector<int> edge[1001];

void dfs(int u){
    visited[u] = true;
    cout << u << ' ';
    sort(edge[u].begin(), edge[u].end());
    for(int v: edge[u]){
        if(visited[v]) continue;
        dfs(v);
    }

}

void bfs(int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()){
        int u = q.front(); q.pop();
        cout << u << ' ';
        sort(edge[u].begin(), edge[u].end());
        for(int v: edge[u]){
            if(visited[v]) continue;
            visited[v] = true;
            q.push(v);
        }
    }
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> V;
    int u, v;
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    dfs(V);
    cout << '\n';
    memset(visited, 0, sizeof(visited));
    bfs(V);

}