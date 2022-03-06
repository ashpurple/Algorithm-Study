#include <iostream>
#include <vector>
#define SIZE 10001
using namespace std;

int V, E, cnt;
int discovered[SIZE];
bool cutVertex[SIZE];
vector<int> edge[SIZE];

int dfs(int cur, bool isRoot){
    discovered[cur] = ++cnt;
    int minNum = discovered[cur]; // earliest discovered num
    
    int child = 0; // the number of child
    for(int next: edge[cur]){
        if(!discovered[next]){
            child++;
            int prev = dfs(next, false); // first visit node
            if(!isRoot && prev >= discovered[cur]) // can't go other way
                cutVertex[cur] = true;
            minNum = min(minNum, prev); // update earliest num
        } 
        else minNum = min(minNum, discovered[next]);
    }
    
    if(isRoot)
        if(child >= 2) cutVertex[cur] = true;
    
    return minNum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E;
    int u, v;
    for(int i = 1; i <= E; i++){
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }

    for(int i = 1; i <= V; i++){
        if(!discovered[i]) dfs(i, true);
    }

    /* print vertex */
    int cutNum = 0;
    for(int i = 1; i <= V; i++)
        cutNum += cutVertex[i];
    cout << cutNum << '\n';

    for(int i = 1; i <= V; i++){
        if(cutVertex[i])
            cout << i << ' ';
    }
    return 0;
}