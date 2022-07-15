#include <iostream>
using namespace std;
const int MAXK = 21;
const int MAX = 1000001;
int N, B;
int IDT[1 << MAXK];

void init(){
    for(B = 1; B < MAX; B <<= 1);
}

void update(int idx, int val){
    idx += (B - 1);
    IDT[idx] += val;
    while(idx >>= 1){
        IDT[idx] = IDT[idx << 1] + IDT[(idx << 1) | 1];
    }
}

int getRank(int rank){
    int idx = 1;
    while(idx < B){
        int left = idx << 1;
        idx = left; // go to left child
        if(rank > IDT[idx]){
            idx++; // go to right siblings
            rank -= IDT[left];
        }
    }
    return idx - (B - 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    init();
    int a, b, c;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        if(a == 1){
            int rank = getRank(b);
            cout << rank << '\n';
            update(rank, -1);
        }
        else{
            cin >> c;
            update(b, c);
        }
    }
}