#include <iostream>
using namespace std;

long long N;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    long long bit;
    for(bit = 1; bit <= N; bit <<= 1);
    bit -= 1;

    if(N == bit){
        cout << 1 << '\n' << bit;
    }
    else{
        cout << 2 << '\n' << bit - N << ' ' << N;
    }
}