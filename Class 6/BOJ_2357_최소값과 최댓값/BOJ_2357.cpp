#include <iostream>
using namespace std;
#define K 21

int N, M;
int num[100000];
int idtMax[1 << K];
int idtMin[1 << K];
int B;

void init(){
    for(B = 1; B < N; B <<= 1);
    for(int i = B; i < B + N; i++) {
        cin >> idtMax[i];
        idtMin[i] = idtMax[i];
    }
    for(int i = B - 1; i > 0; i--){
        idtMax[i] = max(idtMax[i << 1], idtMax[(i << 1) | 1]);
        idtMin[i] = min(idtMin[i << 1], idtMin[(i << 1) | 1]);
    }
}

int getMax(int l, int r){
    l += B - 1;
    r += B - 1;
    int res = 0;
    while (l <= r){
        if((l & 1) == 1) res = max(res, idtMax[l]);
        if((r & 1) == 0) res = max(res, idtMax[r]);

        l = (l + 1) >> 1;
        r = (r - 1) >> 1;
    }
    return res;
}

int getMin(int l, int r){
    l += B - 1;
    r += B - 1;
    int res = 1987654321;
    while (l <= r){
        if((l & 1) == 1) res = min(res, idtMin[l]);
        if((r & 1) == 0) res = min(res, idtMin[r]);

        l = (l + 1) >> 1;
        r = (r - 1) >> 1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    init();

    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        cout << getMin(a, b) << ' ' << getMax(a, b) << '\n';
    }
}