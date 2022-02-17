#include <iostream>
#include <cstring>
using namespace std;
#define MAX 21

int T, N, M;
int idt[1 << MAX];
int movie[100001];
int B;

void init(){
    for(B = 1; B < N + M; B <<= 1);
    for(int i = B + M; i < B + N + M; i++) idt[i] = 1;
    for(int i = B - 1; i > 0; i--){
        idt[i] = idt[i << 1] + idt[(i << 1) | 1];
    }
}

int getSum(int l, int r){
    l += B - 1;
    r += B - 1;
    int sum = 0;
    while(l <= r){
        if((l & 1) == 1) sum += idt[l];
        if((r & 1) == 0) sum += idt[r];
        l = (l + 1) >> 1;
        r = (r - 1) >> 1;
    }
    return sum;
}

void update(int idx, long long num){
    idx += B - 1;
    idt[idx] = num;
    while(idx >>= 1) idt[idx] = idt[idx << 1] + idt[(idx << 1) | 1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> T;
    for(int t = 0; t < T; t++){
        cin >> N >> M;
        memset(idt, 0, sizeof(idt));
        memset(movie, 0, sizeof(movie));
        init();
        for(int i = 1; i <= N; i++) movie[i] = i + M;
        
        for(int i = 0; i < M; i++){
            int pick;
            cin >> pick;
            int idx = movie[pick];
            cout << getSum(1, idx - 1) << " ";
            update(idx, 0); // pop
            update(M - i, 1); // push
            movie[pick] = M - i;
        }
        cout << '\n';
    }

}