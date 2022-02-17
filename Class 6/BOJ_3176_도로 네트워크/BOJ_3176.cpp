#include <iostream>
#include <vector>
using namespace std;
#define MAX 20 // 2^i < n
#define SIZE 100001 // n

struct Edge{
    int vertex;
    int weight;
};

int N, K;
int dp[MAX + 1][SIZE];
int longest[MAX + 1][SIZE];
int shortest[MAX + 1][SIZE];
int depth[SIZE];
bool isVisited[SIZE];
int minimum, maximum;
vector<Edge> edge[SIZE];

void dfs(int n, int d) {
    isVisited[n] = true;
    depth[n] = d; // update depth
    for (Edge child: edge[n]) {
        if (!isVisited[child.vertex]){
            dp[0][child.vertex] = n; // update ancestor to dp
            longest[0][child.vertex] = child.weight;
            shortest[0][child.vertex] = child.weight;
            dfs(child.vertex, d + 1);
        }
    }
}

void setDP() {
    for (int i = 1; i < MAX; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
            longest[i][j] = max(longest[i - 1][j], longest[i - 1][dp[i - 1][j]]);
            shortest[i][j] = min(shortest[i - 1][j], shortest[i - 1][dp[i - 1][j]]);
        }
    }
}
void lca(int x, int y) {
    minimum = 987654321;
    maximum = 0;
    if (depth[x] > depth[y])
        swap(x, y);
    for (int i = MAX; i >= 0; i--) {
        if (depth[y] - depth[x] >= (1 << i)){
            minimum = min(minimum, shortest[i][y]);
            maximum = max(maximum, longest[i][y]);
            y = dp[i][y]; // make same depth
        }
    }
    if (x == y) return; // lca

    for (int i = MAX; i >= 0; i--) {
        if (dp[i][x] != dp[i][y]) {
            // 2^i jump (save time)
            minimum = min(minimum, min(shortest[i][y], shortest[i][x]));
            maximum = max(maximum, max(longest[i][y], longest[i][x]));
            x = dp[i][x];
            y = dp[i][y];
        }
    }
    minimum = min(minimum, min(shortest[0][y], shortest[0][x]));
    maximum = max(maximum, max(longest[0][y], longest[0][x]));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int u, v, w;

    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> u >> v >> w;
        edge[u].push_back({v, w});
        edge[v].push_back({u, w});
    }

    dfs(1, 1);
    setDP();
    cin >> K;
    for(int i = 0; i < K; i++){
        cin >> u >> v;
        lca(u, v);
        cout << minimum << ' ' << maximum << '\n';
    }
}