#include<iostream>
using namespace std;
int N;
int A[1000], B[1000], moveA[1000], moveB[1000];
int dp[2][1000];

int main(int argc, char** argv){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N - 1; i++){
        cin >> A[i] >> B[i] >> moveA[i] >> moveB[i];
    }
    cin >> A[N - 1] >> B[N - 1];

    dp[0][0] = A[0];
    dp[1][0] = B[0];
    for(int i = 0; i < N - 1; i++){
        dp[0][i + 1] = min(dp[0][i], moveB[i] + dp[1][i]) + A[i + 1];
        dp[1][i + 1] = min(dp[1][i], moveA[i] + dp[0][i]) + B[i + 1];
    }

    cout << min(dp[0][N - 1], dp[1][N - 1]);
    return 0;
}