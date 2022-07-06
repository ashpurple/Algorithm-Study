#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXK = 21;
const int MAX = 500000;
int N, M, K, B, T;
long long IDT[1 << MAXK];
int arr[MAX];
vector <int> sorted;

void init(){
    for(B = 1; B < N; B <<=1);
    
    for(int i = B - 1; i > 0; i--){
        IDT[i] = IDT[i << 1] + IDT[(i << 1) | 1];
    }
}

void update(int idx, long long num){
    idx += (B - 1);
    IDT[idx] = num;
    while(idx >>= 1){
        IDT[idx] = (IDT[idx << 1] + IDT[(idx << 1 ) | 1]);
    }
}

long long getSum(int l, int r){
    l += (B - 1); 
    r += (B - 1);
    long long sum = 0;
    while(l <= r){
        if((l & 1) == 1) sum += IDT[l];
        if((r & 1) == 0) sum += IDT[r];

        l = (l + 1) >> 1;
        r = (r - 1) >> 1;
    }
    return sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
        sorted.push_back(arr[i]);
    }

    sort(sorted.begin(), sorted.end());
    init();

    for(int i = 0; i < N; i++){
        int idx = (lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin());
        update(idx, 1);
        cout << (i + 1) - getSum(0, idx - 1) << '\n';
    }
}