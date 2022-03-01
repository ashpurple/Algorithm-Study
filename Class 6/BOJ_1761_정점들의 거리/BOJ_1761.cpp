#include <iostream>
#include <vector>

using namespace std;
#define MAX 20 // 2^i < n
#define SIZE 40001 // n

struct Edge{
    int v;
    int w;
};
int N, M;
int dp[MAX + 1][SIZE];
int dist[MAX + 1][SIZE];
int depth[SIZE];
bool isVisited[SIZE];
vector<Edge> node[SIZE];

void dfs(int n, int d) {
    isVisited[n] = true;
    depth[n] = d; // update depth
    for (Edge edge: node[n]){
        int child = edge.v;
        int weight = edge.w;
        if (!isVisited[child]){
            dp[0][child] = n; // update ancestor to dp
            dist[0][child] = weight;
            dfs(child, d + 1);
        }
    }
}
void setDP() {
    for (int i = 1; i < MAX; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
            dist[i][j] = dist[i - 1][j] + dist[i - 1][dp[i - 1][j]];
        }
    }
}
int lca(int x, int y) {
    int sum = 0;
    if (depth[x] > depth[y]) // y must be deeper
        swap(x, y);
    for (int i = MAX; i >= 0; i--) {
        if (depth[y] - depth[x] >= (1 << i)){
            sum += dist[i][y];
            y = dp[i][y]; // make same depth
        }
    }
    if (x == y) return sum; // lca

    for (int i = MAX; i >= 0; i--) {
        if (dp[i][x] != dp[i][y]) {
            // 2^i jump (save time)
            sum += dist[i][x] + dist[i][y];
            x = dp[i][x];
            y = dp[i][y];
        }
    }
    sum += dist[0][x] + dist[0][y];
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int u, v, w;

    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> u >> v >> w;
        node[u].push_back({v, w});
        node[v].push_back({u, w});
    }

    dfs(1, 1);
    setDP();

    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
}