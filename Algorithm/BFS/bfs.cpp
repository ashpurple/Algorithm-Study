#include <queue>
#include <vector>
using namespace std;

bool visited[10];
vector<int> node[11]; // N = node의 개수, node [N + 1]

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < node[x].size(); i++) {
			int y = node[x][i];
			if (!visited[y]) {
				q.push(y);
				visited[y] = true;
			}
		}
	}
}