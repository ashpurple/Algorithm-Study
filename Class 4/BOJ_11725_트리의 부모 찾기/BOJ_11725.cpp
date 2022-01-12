#include <iostream>
#include <vector>
using namespace std;

bool visited[100001]; 
int parentInfo[100001];
vector<int> node[100001];

void dfs(int parent){
	visited[parent] = true;
	for (int i = 0; i < node[parent].size(); i++){
		int child = node[parent][i];
		if (!visited[child]){
            parentInfo[child] = parent;
            dfs(child);
        }
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int u, v;
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        cin >> u >> v;
        node[u].push_back(v);
        node[v].push_back(u);
    }

    dfs(1);

    for(int i = 2; i <= N; i++)
        cout << parentInfo[i] << '\n';
}