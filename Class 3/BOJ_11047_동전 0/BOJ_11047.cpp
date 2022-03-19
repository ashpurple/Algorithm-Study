#include <iostream>
using namespace std;

int N, K;
int coin[10];
int cnt;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> coin[i];
    
    int idx = N - 1;
    while(K != 0){
        if(coin[idx] <= K){
            K -= coin[idx];
            cnt++;
        } 
        else idx--;
    }

    cout << cnt;
}