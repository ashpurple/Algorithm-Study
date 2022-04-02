#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int cnt = 0;
    while(N >= 0){
        if(N % 5 == 0){
            cnt += N / 5;
            cout << cnt;
            return 0;
        }
        N -= 3;
        cnt++;
    }
    cout << "-1";

}