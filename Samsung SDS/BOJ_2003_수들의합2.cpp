#include <iostream>
using namespace std;
int N, M;
int arr[10000];
int l, r, sum, cnt;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> arr[i];
    
    while(r <= N){
        if(sum < M) sum += arr[r++];
        else sum -= arr[l++];
        if(sum == M) cnt++;
    }
    cout << cnt;
}

