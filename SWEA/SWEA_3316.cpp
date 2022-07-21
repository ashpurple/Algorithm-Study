#include<iostream>
#include<cstring>
using namespace std;
long long dp[10000][16];
const int mod = 1000000007;

int main(int argc, char** argv){
	int T, N;

	cin >> T;
	for(int t = 1; t <= T; t++){
        string input;
		cin >> input;
		
		long long cnt = 0;
		memset(dp, 0, sizeof(dp));

		for (int day = 0; day < input.size(); day++) {
			int master = 1 << (input[day] - 'A');
			
			for (int i = 1; i < 16; i++) {
				if (day == 0) {
					if ((i & master) != 0 && (i & 1) != 0) {
						dp[day][i] = 1;
					}
				}
				else {
					if (dp[day - 1][i] != 0) {
						for (int j = 1; j < 16; j++) {
							if ((i & j) != 0 && (j & master) != 0) {
								dp[day][j] += dp[day - 1][i];
								dp[day][j] %= 1000000007;
							}
						}
					}
				}
			}
		}
		for (int i = 1; i < 16; i++) {
			cnt += dp[input.size() - 1][i];
			cnt %= mod;
		}

        
        cout << "#" << t << ' ' << cnt << '\n';

	}
	return 0;
}