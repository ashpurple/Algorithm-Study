#include <iostream>
using namespace std;

long long int a, b, c;

long long int pow(long long int x, long long int n){
    if(n == 0)
        return 1;
    else if (n == 1)
        return x;

    if((n & 1) == 1) // odd
        return pow(x, n - 1) * x;
    else{ // even
        long long int divide = pow(x, n >> 1) % c;
        return (divide * divide) % c;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b >> c;

    cout << pow(a, b) % c;
}