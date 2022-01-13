#include <iostream>
using namespace std;

int arr[100001];
int dp[100001] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int a, b, sum;

    cin >> N >> M;
    for(int i = 1; i < N + 1; i++){
        cin >> arr[i];
    }

    for(int i = 1; i < N + 1; i++){
        dp[i] = dp[i - 1] + arr[i];
    }

    for(int i = 0; i < M; i++){
        cin >> a >> b;
        sum = dp[b] - dp[a - 1];
        cout << sum << '\n';
    }
    
}