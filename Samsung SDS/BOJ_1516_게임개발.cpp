#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 501; 
int N, M;
vector<int> node[MAX];
int buildTime[MAX];
int inDegree[MAX];
int dp[MAX];

void topologySort(){
    queue<int> q;
    for(int i = 1; i <= N; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
        dp[i] = buildTime[i];
    }

    for(int i = 1; i <= N; i++){
        if(q.empty()) return;

        int u = q.front();
        q.pop();

        for(int v : node[u]){
            dp[v] = max(dp[v], dp[u] + buildTime[v]);
            if(--inDegree[v] == 0){
                q.push(v);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int u, v;
    for(int i = 1; i <= N; i++){
        int num;
        cin >> num;
        buildTime[i] = num;
        while(true){
            cin >> num;
            if(num == -1) break;
            node[num].push_back(i);
            inDegree[i]++;
        }
    }

    topologySort();

    for(int i = 1; i <= N; i++)
        cout << dp[i] << '\n';
}