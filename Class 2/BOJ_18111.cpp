#include <iostream>
using namespace std;
int N, M, B;
int map[500][500];
int ans = 1987654321;
int height;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> B;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++) 
			cin >> map[i][j];

	for (int h = 0; h <= 256; h++) {
		int buildCnt = 0;
		int removeCnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				int diff = map[i][j] - h;
				if (diff > 0) removeCnt += diff;
				else buildCnt -= diff;
			}
		}

		if (removeCnt + B >= buildCnt) {
			int time = removeCnt * 2 + buildCnt;
			if (ans >= time) {
				ans = time;
				height = h;
			}
		}
	}
    cout << ans << ' ' << height <<'\n';
}