#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;

    cin >> num;
    if(num % 400 == 0)
        cout << 1;
    else if(num % 4 == 0 && num % 100 != 0)
        cout << 1;
    else cout << 0;
}