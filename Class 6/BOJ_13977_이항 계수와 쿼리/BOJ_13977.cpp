#include <iostream>
using namespace std;

const int MOD = 1000000007;
const int SIZE = 4000001;
int N, M, K;
long long fact[SIZE];

long long pow(long long num, int exp){
    if(exp == 0) return 1;
    if(exp == 1) return num;
    if((exp & 1) == 0){
        long long half = pow(num, exp >> 1);
        return (half * half) % MOD;
    }
    if((exp & 1) == 1){
        long long one = pow(num, exp - 1);
        return (num * one) % MOD;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> M;
    
    fact[0] = 1;
    for(int i = 1; i < SIZE; i++)
        fact[i] = (i * fact[i - 1]) % MOD;


    for(int i = 0; i < M; i++){
        cin >> N >> K;
        long long a = fact[N];
        long long b = (fact[K] * fact[N - K]) % MOD;
        b = pow(b, MOD - 2);
        cout << (a * b) % MOD << '\n';
    }
    
    
}