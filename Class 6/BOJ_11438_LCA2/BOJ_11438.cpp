#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define MAX 20 // 2^i < n
#define SIZE 100001 // n

int N, M;
int dp[MAX + 1][SIZE];
int depth[SIZE];
bool isVisited[SIZE] = {false};
vector<int> node[SIZE];

void dfs(int n, int d) {
    isVisited[n] = true;
    depth[n] = d; // update depth
    int child;
    for (int i = 0; i < node[n].size(); i++) {
        child = node[n].at(i);
        if (!isVisited[child]){
            dp[0][child] = n; // update ancestor to dp
            dfs(child, d + 1);
        }
    }
}
void setDP() {
    for (int i = 1; i < MAX; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
}
int lca(int x, int y) {
    if (depth[x] > depth[y]) // go up
        swap(x, y);
    for (int i = MAX; i >= 0; i--) {
        // 2^i jump (save time)
        if (depth[y] - depth[x] >= (1 << i))
            y = dp[i][y];
    }
    if (x == y) return x; // lca

    for (int i = MAX; i >= 0; i--) {
        if (dp[i][x] != dp[i][y]) {
            x = dp[i][x];
            y = dp[i][y];
        }
    }
    return dp[0][x];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int u, v;

    cin >> N;
    for (int i = 1; i < N; i++) {
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }

    dfs(1, 1);
    setDP();

    cin >> M;
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
}