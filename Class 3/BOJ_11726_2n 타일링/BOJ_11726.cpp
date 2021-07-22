#include <iostream>
using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int dp[1001];

    cin >> N;
    
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= N; i++){
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    }
    cout << dp[N];
}

