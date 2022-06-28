#include <iostream>
#include <vector>
#include <queue>
#define INF 1987654321
#define STATION 10001
#define LINE 1001
using namespace std;
int T, N, M, S, E;
int lineNum[LINE];
vector<int> line[LINE];
vector<int> station[STATION];
int cnt[STATION];
bool visited[LINE];

void init(){
    for(int i = 0; i < STATION; i++){
        station[i].clear();
        cnt[i] = INF;
    }
    for(int i = 0; i < LINE; i++){
        line[i].clear();
        visited[i] = false;
    }
}

void bfs() {
	queue<int> q;
	q.push(S);
	cnt[S] = -1;

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int nextLine : station[cur]) {
			if (visited[nextLine]) continue;
			visited[nextLine] = true;
			for (int nextStation : line[nextLine]) {
				if (cnt[nextStation] == INF) {
					cnt[nextStation] = cnt[cur] + 1;
					q.push(nextStation);
				}
			}
		}
	}
	cnt[S] = 0;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> T;
    for(int t = 1; t <= T; t++){
        init();

        cin >> N >> M >> S >> E;
        for(int i = 0; i < M; i++){
            cin >> lineNum[i];
        }

        for(int i = 0; i < M; i++){
            for(int j = 0; j < lineNum[i]; j++){
                int num;
                cin >> num;
                line[i].push_back(num);
			    station[num].push_back(i);
            }
        }

	    bfs();

        if (cnt[E] == INF) cout << '#' << t << ' ' << -1 << '\n';
        else cout << '#' << t << ' ' << cnt[E] << '\n';
    }
}
