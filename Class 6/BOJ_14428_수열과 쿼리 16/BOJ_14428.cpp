#include <iostream>
#define BIT 21
using namespace std;

struct Data{
    int val;
    int idx;
    bool operator<(const Data other){
        if(val == other.val) return idx < other.idx;
        return val < other.val;
    }
};

int N, M, K;
Data idt[1 << BIT];
int B;

Data cmp(Data a, Data b){
    if(a < b){
        return a;
    } 
    return b;
}

void init(){
    for(B = 1; N > B; B <<= 1);

    for(int i = B; i < B + N; i++){
        cin >> idt[i].val;
        idt[i].idx = i - B + 1;
    }

    for(int i = B - 1; 0 < i; i--)
        idt[i] = cmp(idt[i << 1], idt[(i << 1) | 1]);
}

void update(int idx, int val){
    int temp = idx;
    idx += (B - 1);
    idt[idx] = {val, temp};

    while(idx >>= 1){
        idt[idx] = cmp(idt[idx << 1], idt[(idx << 1) | 1]);
    }
}

int getMinIdx(int l, int r){
    l += (B - 1);
    r += (B - 1);

    int INF = 1987654321;
    Data minimum = {INF, 0};
    while(l <= r){
        if((l & 1) == 1) minimum = cmp(minimum, idt[l]);
        if((r & 1) == 0) minimum = cmp(minimum, idt[r]);
        l = (l + 1) >> 1;
        r = (r - 1) >> 1; 
    }
    return minimum.idx;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;;
    init();
    cin >> M;
    int op, a, b;
    for(int i = 0; i < M; i++){
        cin >> op >> a >> b;
        if(op == 1) update(a, b);
        else cout << getMinIdx(a, b) << '\n';
    }

}