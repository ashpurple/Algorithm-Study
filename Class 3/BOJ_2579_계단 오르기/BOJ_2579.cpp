#include <iostream>
using namespace std;
int N;
int arr[300];
int dp[300];

void simulate(){
    dp[0] = arr[0];
    dp[1] = arr[0] + arr[1];
    dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);
    for(int i = 3; i < N; i++)
        dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;

    for(int i = 0; i < N; i++) cin >> arr[i];
    simulate();
    cout << dp[N - 1];
}