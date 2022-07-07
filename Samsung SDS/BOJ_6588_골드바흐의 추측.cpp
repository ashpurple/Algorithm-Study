#include <iostream>
#include <math.h>
using namespace std;
const int MAX = 1000000;

bool isPrime(int num){
    for (int i = 2; i <= sqrt(num); i++){
        if(num % i == 0) return false;
    }
    return true;
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    while(true){
        cin >> num;
        if(num == 0) break;
        int end = num / 2;
        bool flag = true;
        for(int i = 3; i <= end; i+=2){
            if(isPrime(i) && isPrime(num - i)){
                flag = false;
                cout << num << " = " << i << " + " << num - i << '\n';
                break;
            }
        }
        if(flag) cout << "Goldbach's conjecture is wrong.\n"; 
    }

}
