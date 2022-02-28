#include <iostream>
using namespace std;

int phi(int N){
    int x = N;
    for(int i = 2; i * i <= N; i++){
        if(N % i == 0){ // 인수일때
            x = x - (x / i); // 오일러 pi 함수 전개
            while(N % i == 0) N /= i; // 소인수 제거
        }
    }
    if(N > 1) x = x - (x / N); // 소인수가 남아있을때
    return x;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    cout << phi(N);
    
}