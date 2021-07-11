#include <iostream>
#include <math.h>

using namespace std;
bool isPrime(int number){
    if(number <= 1)
        return false;
    for(int i = 2; i <= sqrt(number); i++){
        if((number % i ) == 0)
            return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, input, cnt = 0;

    cin >> num;
    for(int i = 0; i < num; i++){
        cin >> input;
        if(isPrime(input))
            cnt++;
    }
    cout << cnt;
}