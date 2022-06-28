#include <iostream>
#include <string.h>
using namespace std;

const int MAXN = 100;
const int MOD = 1000000007;
const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,-1,0,1 };

int T, N, M, K, page;
long long dp[2][MAXN][MAXN];
string map[MAXN];

void solve(int x) {
	memset(dp, 0, sizeof dp);

	page = 0;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> map[i];
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 'S') dp[page][i][j] = 1;
		}
	}
	long long ans = 0;

	while (K--) {
		for (int i = 0; i < N; i++) {
			ans = (ans + dp[page][i][0]) % MOD;
			ans = (ans + dp[page][i][M - 1]) % MOD;
		}
		for (int i = 0; i < M; i++) {
			ans = (ans + dp[page][0][i]) % MOD;
			ans = (ans + dp[page][N - 1][i]) % MOD;
		}
		if (K == 0) break;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 'X') continue;

				long long sum = 0;
				for (int d = 0; d < 4; d++) {
					int ni = i + dx[d];
					int nj = j + dy[d];

					if (ni < 0 || ni >= N || nj < 0 || nj >= M || map[ni][nj] == 'X') continue;

					sum = (sum + dp[page][ni][nj]) % MOD;
				}
				dp[page ^ 1][i][j] = sum;
			}
		}
		page ^= 1;
	
	}
	
	cout << '#' << x << ' ' << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for (int i = 1; i <= T; i++) {
		solve(i);
	}

