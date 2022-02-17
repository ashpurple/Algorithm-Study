#include <iostream>
#define NUM 100001
using namespace std;

int N, M;
int cnt;
int root[NUM];

int find(int x){
    if(root[x] == x) return x;
    else return root[x] = find(root[x]);
}

void Union(int x, int y){
    x = find(x);
    y = find(y);
    root[x] = y;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int u, v, w;
    cin >> N >> M;
    for(int i = 0; i <= N; i++) root[i] = i;
    int gate;
    for(int i = 0; i < M; i++){
        cin >> gate;
        int emptyGate = find(gate);
        if(emptyGate == 0) break;
        else{
            cnt++;
            Union(emptyGate, emptyGate - 1);
        }
    }
    cout << cnt;
}