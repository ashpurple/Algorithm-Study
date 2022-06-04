#include <iostream>
using namespace std;
const int MOD = 1000000007;
long long ans = 1;
long long score;
long long sum;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    for(int i = 2; i <= N; i++){
        ans *= i;
        ans %= MOD;
    }

    
    for(int i = 1; i <= N; i++){
        sum += (i * 2);
        score += (sum * i);
        score %= MOD;
    }

    cout << score << ' ' << (ans * ans) % MOD;
}