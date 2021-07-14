#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];
int operation(int);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;

    cin >> N;
    cout << operation(N);
}

int operation(int num){
    
    dp[1] = 0;
    for(int i = 2; i <= num; i++){
        dp[i] = dp[i - 1] + 1;

        if(i % 3 == 0)
            dp[i] = min(dp[i / 3] + 1, dp[i]);
        if(i % 2 == 0)
            dp[i] = min(dp[i / 2] + 1, dp[i]);
    }
    return dp[num];
}
