#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, sum = 0;
    string numbers;

    cin >> num >> numbers;

    for(int i = 0; i < num; i++){
        sum += numbers[i] - '0';
    }
    cout << sum << '\n';
}