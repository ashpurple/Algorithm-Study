#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K;
    cin >> N >> M >> K;

    int ans = (M + (K - 4)) % N;
    if(ans > 0) cout << ans + 1;
    else {
        if((ans + N + 1) % N == 0) cout << N;
        else cout << (ans + N + 1) % N;
    }

}