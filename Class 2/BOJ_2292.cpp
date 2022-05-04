#include <iostream>
using namespace std;
int N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    int num = 1;
    int cnt = 0;
    while(true){
        cnt++;
        if(N <= num) break;
        num = num + (6 * cnt);
    }
    cout << cnt;
}