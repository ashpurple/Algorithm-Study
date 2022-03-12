#include <iostream>
using namespace std;

int T, N;
long long dp[101];

void solution(){
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    for(int i = 6; i <= N; i++){
        dp[i] = dp[i - 1] + dp[i - 5];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int t = 0; t < T; t++){
        cin >> N;
        solution();
        cout << dp[N] << '\n';
    }
}