#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int H, M;
    cin >> H >> M;
    int min = H * 60 + M - 45;
    if(min < 0) min += 60 * 24;
    cout << min / 60 << ' ' << min % 60;
}