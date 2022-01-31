#include <iostream>
#include <vector>
#include <queue>
#define MAX 32001 // node + 1
using namespace std;

int N; // the number of node
int M; // the number of edge
vector<int> node[MAX];
int inDegree[MAX];
int result[MAX];

void topologySort(){
    queue<int> q;

    for(int i = 1; i <= N; i++) // start node
        if(inDegree[i] == 0) q.push(i);

    for(int i = 1; i <= N; i++){
        if(q.empty()){
            cout << "Cycle";
            return;
        }

        int u = q.front();
        q.pop();
        result[i] = u; // make result

        for(int j = 0; j < node[u].size(); j++){
            int v = node[u][j];
            // push new zero inDegrees to queue
            if(--inDegree[v] == 0) q.push(v);
        }
    }
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    int u, v;
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        node[u].push_back(v);
        inDegree[v]++;
    }

    topologySort();

    for(int i = 1; i <= N; i++)
        cout << result[i] << " ";
}