#include <iostream>
using namespace std;

int T, N;
int arr[2][100002];
int dp[2][100002];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int t = 1; t <= T; t++){
        cin >> N;

        for(int i = 2; i < N + 2; i++){
            cin >> arr[0][i];
        }
        for(int i = 2; i < N + 2; i++){
            cin >> arr[1][i];
        }

        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[1][0] = 0;
        dp[1][1] = 0;

        for(int i = 2; i < N + 2; i++){
            dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + arr[0][i];
            dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + arr[1][i];
        }

        int ans = max(dp[0][N + 1], dp[1][N + 1]);
        cout << ans << '\n';
    }
}