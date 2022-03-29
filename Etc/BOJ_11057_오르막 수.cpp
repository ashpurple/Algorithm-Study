#include <iostream>
using namespace std;
const int MOD = 10007;
int num;
int dp[1001][10];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> num;

    for(int i = 0; i < 10; i++)
        dp[1][i] = 1;
    

    for(int i = 1; i <= num; i++){ 
        for(int j = 0; j < 10; j++){
            for(int k = 0; k <= j; k++){
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= MOD;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < 10; i++)
        ans += dp[num][i];
    cout << ans % MOD;
}