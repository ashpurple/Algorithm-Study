#include <iostream>
using namespace std;
int a[1000], b[1000];
int maxDiff;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    
    for(int i = 0; i < N; i++) cin >> a[i];

    for(int i = 0; i < M; i++){
        cin >> b[i];
        maxDiff = max(maxDiff, b[i] - a[i]);
    }
    cout << maxDiff;
}