#include <iostream>
#define MAX 100000
using namespace std;

int N, K;
int num[MAX];
int dp[MAX + 1];
int rdp[MAX + 1];

int main(){
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    int sum = 0;
    for(int i = 0; i < N; i++){
        cin >> num[i];
        sum += num[i];
        dp[i + 1] = sum;
    }
    sum = 0;
    for(int i = N - 1; 0 <= i; i--){
        sum += num[i];
        rdp[i] = sum;
    }

    int ans = 0;
    for(int i = K; i <= N; i++){
        int temp = dp[i] - dp[i - K];
        ans = max(ans, temp);
    }
    
    for(int i = 0; i < K - 1; i++){
        int temp = dp[i + 1] + rdp[N - K + i + 1];
        ans = max(ans, temp);
    }

    cout << ans;
}