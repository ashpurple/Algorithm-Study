#include <iostream>
using namespace std;
int gcd(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int x = a * d + b * c;
    int y = b * d;
    int div = gcd(x, y);
    cout << x / div << ' ' << y / div;

}
