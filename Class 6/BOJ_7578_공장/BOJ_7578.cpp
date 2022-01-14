#include <iostream>
using namespace std;
int N;
int A[500001];
int B[1000001];
int bit;
long long tree[1<<20];

void init(){
    for(bit = 1; bit < N; bit<<=1);
}

long long getSum(int l, int r){ // lth to rth
    l += (bit - 1); 
    r += (bit - 1);
    long long sum = 0;
    while(l <= r){
        if((l & 1) == 1) sum += tree[l]; // left = odd
        if((r & 1) == 0) sum += tree[r]; // right = even

        l = (l + 1) >> 1;
        r = (r - 1) >> 1;
    }
    return sum;
}

void update(int idx){
    idx += (bit - 1);
    tree[idx] += 1;
    while(idx >>= 1){
        tree[idx] = (tree[idx << 1] + tree[(idx << 1 ) | 1]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int idx;
    long long ans = 0;

    cin >> N;
    for(int i = 1; i <= N; i++) 
        cin >> A[i];
    for(int i = 1; i <= N; i++){
        cin >> idx;
        B[idx] = i;
    }
    
    init();

    for(int i = 1; i <= N; i++){
        int target = B[A[i]];
        ans += getSum(target + 1, N); // sum += right visit
        update(target); // visit
    }
    cout << ans;

}
