#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
int N;
string str;
const int MOD = 1000000007;
int cnt[200000][2];

ll pow(ll x, int n) {
    ll res = 1;
    if (n == 0) return 1;
    while (n > 1) {
        if (n & 1) res = (res * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;
    }
    return (x * res) % MOD;
}

ll calculate(int idx){
    int wCnt = cnt[idx][0];
    int eCnt = cnt[idx][1];
    ll powNum = pow(2, eCnt);
    return wCnt * (powNum - eCnt - 1 + MOD);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    cin >> str;
    ll ans = 0;
    int wCnt = 0, eCnt = 0;

    for(int i = 0; i < N; i++){
        if(str[i] == 'W') wCnt++;
        cnt[i][0] = wCnt;
    }
    for(int i = N - 1; 0 <= i; i--){
        if(str[i] == 'E') eCnt++;
        cnt[i][1] = eCnt;
    }

    for(int i = 0; i < N; i++){
        if(str[i] == 'H'){
            ans += calculate(i);
            ans %= MOD;
        }
    }
    cout << ans;
}