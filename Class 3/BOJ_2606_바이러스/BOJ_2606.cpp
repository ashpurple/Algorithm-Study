#include <iostream>
#include <vector>
using namespace std;

void dfs(int);

bool visited[101]; 
vector<int> node[101];
int cnt = -1;

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
    dfs(1);
	cout << cnt;
}

void dfs(int parent){
	visited[parent] = true;
    cnt++;
	for (int i = 0; i < node[parent].size(); i++){
		int child = node[parent][i];
		if (!visited[child])
            dfs(child);
	}
}