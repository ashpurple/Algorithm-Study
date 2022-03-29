#include <iostream>
using namespace std;
const int SIZE = 101;
const int MOD = 1000000000;
int N;
int dp[SIZE][11];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    for(int i = 2; i <= 10; i++)
        dp[1][i] = 1;

    for(int i = 2; i <= N; i++){
        for(int j = 1; j <= 10; j++){
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
            dp[i][j] %= MOD;
        }
    }

    int sum = 0;
    for(int i = 1; i <= 10; i++) sum = (sum + dp[N][i]) % MOD;
    cout << sum;
}