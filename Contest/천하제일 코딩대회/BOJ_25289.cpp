#include <iostream>
#include <string.h>
using namespace std;
int N;
int arr[100000];
int dp[101];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];

    int ans = 0;
    for(int diff = -99; diff < 100; diff++){
        memset(dp, 0, 101 * sizeof(int));
        for(int i = 0; i < N; i++){
            int d = arr[i] - diff;
            if(d < 1 || d > 100) dp[arr[i]] = 1;
            else dp[arr[i]] = dp[d] + 1;
            ans = max(ans, dp[arr[i]]); 
        }
    }
    cout << ans;
}