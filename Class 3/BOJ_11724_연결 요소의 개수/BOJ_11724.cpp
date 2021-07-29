#include <iostream>
#include <vector>
using namespace std;

void dfs(int);

bool visited[1001]; 
vector<int> node[1001];
int cnt = 0;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, edge;
    cin >> N >> edge;
    
    for(int i = 1; i <= edge; i++){
        int u, v;
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }
    for(int i = 1; i <= N; i ++){
        if(!visited[i]){
            dfs(i);
            cnt++;
        }
    }
    
	cout << cnt;
}

void dfs(int parent){
	visited[parent] = true;
	for (int i = 0; i < node[parent].size(); i++){
		int child = node[parent][i];
		if (!visited[child])
            dfs(child);
	}
}