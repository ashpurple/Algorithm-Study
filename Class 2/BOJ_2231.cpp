#include <iostream>
using namespace std;

int getSum(int num){
    int sum = num;
    while(num > 0){
        sum = sum + (num % 10);
        num /= 10;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int num = 1;
    bool flag = false;
    cin >> N;

    while(num <= N){
        if(N == getSum(num)){
            flag = true;
            break;
        }
        num++;
    }
    if(flag) cout << num;
    else cout << 0;
}