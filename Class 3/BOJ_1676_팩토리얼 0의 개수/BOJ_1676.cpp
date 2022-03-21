#include <iostream>
using namespace std;
int N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int cnt = 0;
    while(N != 0){
        N /= 5;
        cnt += N;
    }
    cout << cnt;
}