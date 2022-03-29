#include <iostream>
using namespace std;
const int SIZE = 1000001;
const int MOD = 15746;
int N;
int dp[SIZE];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= N; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] %= MOD;
    }
    cout << dp[N];
}