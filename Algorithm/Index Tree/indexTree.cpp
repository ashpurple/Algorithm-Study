#include <iostream>
using namespace std;

#define MAXK 21 // height

int N, M, K, B, T;
long long IDT[1 << MAXK];

void init(){
    for(B = 1; B < N; B <<=1); // 리프노드의 시작 인덱스 설정

    for(int i = B; i < N + B; i++){ 
        cin >> IDT[i];
    }

    for(int i = B - 1; i > 0; i--){ // non leaf node 설정
        IDT[i] = (IDT[i << 1] + IDT[(i << 1) | 1]); // left + right
    }
}

void update(int idx, long long num){
    idx += (B - 1);
    IDT[idx] = num;
    while(idx >>= 1){
        IDT[idx] = (IDT[idx << 1] + IDT[(idx << 1 ) | 1]);
    }
}

long long getSum(int l, int r){ // lth to rth
    l += (B - 1); 
    r += (B - 1);
    long long sum = 0;
    while(l <= r){
        if((l & 1) == 1) sum += IDT[l]; // left = odd
        if((r & 1) == 0) sum += IDT[r]; // right = even

        l = (l + 1) >> 1;
        r = (r - 1) >> 1;
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    init();

    T = M + K;

    int a, b;
    long long c;
    while(T--){
        cin >> a >> b >> c;

        if(a == 1) update(b, c);
        else cout << getSum(b, c) << '\n';
    }
}