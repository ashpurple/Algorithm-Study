#include <iostream>
using namespace std;
const int MOD = 10007;
int dp[1001];

int N;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> N;

	dp[1] = 1;
	dp[2] = 3;
	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % MOD;
	}
	cout << dp[N];
}