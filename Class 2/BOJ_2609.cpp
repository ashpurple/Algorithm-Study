#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(b == 0)
        return a;
    else
        return gcd(b, a % b); 
}

int lcm(int a, int b){
    return a * (b / gcd(a, b));
}

int main() {
    int A, B;
    cin >> A >> B;
    cout << gcd(A, B) << '\n' << lcm(A, B);
}