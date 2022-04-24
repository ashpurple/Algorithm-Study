#include <iostream>
#include <string>
#include <vector>
#define MAX 20 
#define SIZE 1001 
using namespace std;
int MOD = 1000000007;
int N, Q;
vector<int> edge[SIZE];
string door[SIZE];
bool visited[SIZE];
int dp[SIZE];
int depth[SIZE];

void dfs(int n, int d) {
    visited[n] = true;
    depth[n] = d; 
    for (int child: edge[n]) {
        if (!visited[child]){
            dp[child] = n; 
            dfs(child, d + 1);
        }
    }
}

string lca(int x, int y) {
    string a = "";
    string b = "";
    bool flag = true;
    while(depth[y] != depth[x]) {
        if (depth[y] < depth[x]){
            flag = true;
            a = a + door[x];
            x = dp[x];
        } else{
            flag = false;
            b = door[y] + b;
            y = dp[y];
        }
    }
    if (x == y){
        if(flag) return a + door[x]; 
        else return door[x] + b; 
    }
    while (x != y) {
            a = a + door[x];
            b = door[y] + b;
            x = dp[x];
            y = dp[y];
    }
    a = a + door[x];
    return a + b;
}

long long mod(string num){
    long long res = 0;
    for (int i = 0; i < num.length(); i++)
        res = (res * 10 + (long long)num[i] - '0') % MOD;
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> Q;
    for(int i = 1; i <= N; i++){
        cin >> door[i];
    }
    
    int u, v;
    for(int i = 0; i < N - 1; i++){
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1, 1);
    int start, finish;
    for(int i = 0; i < Q; i++){
        cin >> start >> finish;
        string str = lca(start, finish);
        cout << mod(str) << '\n';
    }
}