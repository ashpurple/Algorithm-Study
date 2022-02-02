#include <iostream>
using namespace std;

int N, M;
int mem[101];
int cost[101];
int dp[101][10001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sum = 0;
    cin >> N >> M;
    
    for(int i = 1; i <= N; i++){
        cin >> mem[i];
    }
    for(int i = 1; i <= N; i++){
        cin >> cost[i];
        sum += cost[i];
    }

    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= sum; j++){
            if(cost[i] <= j) // can put in
                // max(didn't put sum, put sum)
                // put sum = currentValue + pastValue(total size - current size)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + mem[i]);
            else // can't put in
                dp[i][j] = dp[i - 1][j];
        }
    }

    for(int i = 0; i <= sum; i++){
        if(dp[N][i] >= M){
            cout << i;
            break;
        }
    }
}