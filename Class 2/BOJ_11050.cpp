#include <iostream>
using namespace std;

int factorial(int num){
    if(num == 1 || num == 0){
        return 1;
    }
    else{
        return factorial(num - 1) * num;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    cout << factorial(N) / (factorial(K) * factorial(N - K));
}