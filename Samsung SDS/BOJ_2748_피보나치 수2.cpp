#include <iostream>
using namespace std;
int N;
long long dp[100];

void fibo(int num){
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= num; i++) dp[i] = dp[i - 1] + dp[i - 2]; 
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    fibo(N);
    cout << dp[N];
}
