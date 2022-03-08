#include <iostream>
#define BIT 21
#define MOD 1000000007
using namespace std;

int N, M, K;
long long idt[1 << BIT];
int B;

void init(){
    for(B = 1; N > B; B <<= 1);

    for(int i = B; i < B + N; i++) cin >> idt[i];

    for(int i = B - 1; 0 < i; i--)
        idt[i] = (idt[i << 1] * idt[(i << 1) | 1]) % MOD;
}

void update(int idx, long long val){
    idx += (B - 1);
    idt[idx] = val;

    while(idx >>= 1){
        idt[idx] = (idt[idx << 1] * idt[(idx << 1) | 1]) % MOD;
    }
}

long long getMul(int l, int r){
    l += (B - 1);
    r += (B - 1);

    long long mul = 1;
    while(l <= r){
        if((l & 1) == 1) mul = (mul * idt[l]) % MOD;
        if((r & 1) == 0) mul = (mul * idt[r]) % MOD;
        l = (l + 1) >> 1;
        r = (r - 1) >> 1; 
    }
    return mul;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
    init();

    int op, a, b;
    for(int i = 0; i < M + K; i++){
        cin >> op >> a >> b;
        if(op == 1) update(a, b);
        else cout << getMul(a, b) << '\n';
    }

}