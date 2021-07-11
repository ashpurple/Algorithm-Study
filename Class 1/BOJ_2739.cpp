#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;

    cin >> num;

    for(int i = 1; i < 10; i++){
        cout << num << " * " << i << " = " << num * i << '\n';
    }
}