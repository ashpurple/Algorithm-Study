#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x, y, w, h;

    cin >> x >> y >> w >> h;

    int minW = min(x, w - x);;
    int minH = min(y, h - y);
    int minimum = min(minW, minH);
    cout << minimum;
}