#include <iostream>
using namespace std;

int tri[501][501];
int dp[501][501] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < i + 1; j++){
            cin >> tri[i][j];
        }
    }

    dp[1][1] = tri[1][1];
    for(int i = 2; i < n + 1; i++){
        for(int j = 1; j < i + 1; j++){
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tri[i][j];
        }
    }
    
    int max = 0;
    for(int i = 1; i < n + 1; i++){
        if(max < dp[n][i])
            max = dp[n][i];
    }

    cout << max;
}