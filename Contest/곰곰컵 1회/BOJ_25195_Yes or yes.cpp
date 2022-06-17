#include <iostream>
#include <vector>
using namespace std;
int N, M, S;
int flag;
vector <int> edge[100001];

void dfs(int u){
    for(int v : edge[u]){
        if(v == -1) return;
        dfs(v);
    }

    if(edge[u].size() == 0) flag = true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
    }

    cin >> S;
    for(int i = 0; i < S; i++){
        int num;
        cin >> num;
        edge[num].clear();
        edge[num].push_back(-1);
    }

    dfs(1);
    
    if(flag) cout << "yes";
    else cout << "Yes";
}