#include <iostream>
#include <cstring>
#include <vector>
#define SIZE 10001
using namespace std;
int V, E;
int scc[SIZE];
int groupNum;
bool visited[SIZE];
vector<int> edge[SIZE], r_edge[SIZE];
vector<int> STACK;

void dfs(int cur) {
	visited[cur] = true;
	for(int i: edge[cur])
		if (!visited[i]) dfs(i);
    // 더이상 방문할 정점이 없으면
	STACK.push_back(cur); // 깊은 노드부터 스택 푸쉬
}

void r_dfs(int cur, int num) {
	visited[cur] = true;
	scc[cur] = num; // SCC 번호 부여
	for (int i : r_edge[cur])
		if (!visited[i]) r_dfs(i, num);
}

void SCC(){
    /* 순그래프 탐색 (스택 쌓기) */
	for(int i = 1; i <= V; i++) 
		if(!visited[i]) dfs(i);

    /* 역그래프 탐색 (SCC 구축)*/
	memset(visited, 0, sizeof(visited));
	while (!STACK.empty()){
		int cur = STACK.back(); STACK.pop_back();
		if (visited[cur]) continue;
		r_dfs(cur, ++groupNum);
	}

    /* 출력 */
	cout << groupNum << '\n';
	for (int i = 1; i <= V; i++) {
		if (scc[i] == 0) continue;
		cout << i << ' ';
		for(int j = i + 1; j <= V; j++)
			if (scc[j] == scc[i]) {
				cout << j << ' ';
				scc[j] = 0;
			}
		cout << -1 << '\n';
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> V >> E;
    int u, v;
	for (int i = 0; i < E; i++) {
		cin >> u >> v;
		edge[u].push_back(v);
		r_edge[v].push_back(u);
	}

    SCC();
    
	return 0;
}