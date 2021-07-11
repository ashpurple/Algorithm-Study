#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B;
    cin >> A >> B;
    cout.precision(9);
    cout << fixed << (double)A / B;
}