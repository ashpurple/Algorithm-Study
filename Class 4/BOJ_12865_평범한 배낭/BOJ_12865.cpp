#include <iostream>
using namespace std;

int N, K;
int V[101];
int W[101];
int dp[101][100001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    
    for(int i = 1; i <= N; i++){
        cin >> W[i] >> V[i];
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= K; j++){
            if(0 <= j - W[i]) // can put in
                // max(didn't put sum, put sum)
                // put sum = currentValue + pastValue(total size - current size)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
            else // can't put in
                dp[i][j] = dp[i - 1][j];
        }
    }
    cout << dp[N][K];
}