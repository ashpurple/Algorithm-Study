#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<pair<int, int>> chicken;
vector<pair<int, int>> home;
vector<int> visited;
int N, M;
int MIN_DISTANCE = 0x7fffffff;

int simulate() {
	int res = 0;

	for (int i = 0; i < home.size(); i++) {
		int dist = 3 * N;
		for (int j = 0; j < chicken.size(); j++) {
			if (visited[j] == 1) {
				dist = min(dist, abs(chicken[j].first - home[i].first) + abs(chicken[j].second - home[i].second));
			}
		}
		res += dist;
	}

	return res;
}

void dfs(int start, int count) {
	if (start >= chicken.size() || count == M) {
		return;
	}

	for (int i = start; i < chicken.size(); i++) {	
		if (visited[i] == 0 && count < M) {
			visited[i] = 1;
			MIN_DISTANCE = min(MIN_DISTANCE, simulate());
			dfs(i + 1, count + 1);
			visited[i] = 0;
		}
	}
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int input;

			cin >> input;

			if (input == 1)
				home.push_back(make_pair(i, j));
			if (input == 2) {
				chicken.push_back(make_pair(i, j));
				visited.push_back(0);
			}
		}
	}

	dfs(0, 0);

	cout << MIN_DISTANCE << '\n';
    
    
}