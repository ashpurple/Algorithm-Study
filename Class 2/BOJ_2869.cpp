#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int A, B, V;
    cin >> A >> B >> V;
    
    int diff = A - B;
    int res = V - A;
    
    if(res % diff != 0) {
        res /= diff;
        res++;
    }
    else{
        res /= diff;
    }
    cout << res + 1;
 
}