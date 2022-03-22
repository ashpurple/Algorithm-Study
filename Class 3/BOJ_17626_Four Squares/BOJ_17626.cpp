#include <iostream>
using namespace std;
int N;
int dp[50001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    dp[1] = 1;
    for(int i = 1; i <= N; i++){
        dp[i] = dp[1] + dp[i - 1];
        for(int j = 2; j * j <= i; j++){
            dp[i] = min(dp[i], 1 + dp[i - j * j]);
        }
    }
    cout << dp[N];

}