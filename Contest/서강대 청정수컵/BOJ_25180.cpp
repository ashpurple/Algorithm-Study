#include <iostream>
using namespace std;
int N;
int ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int div = N / 9;
    int mod = N % 9;
    if(N < 10) ans = 1;
    else if(mod == 0) ans = div;
    else if((mod & 1) == 1) ans = div + 1;
    else if((div & 1) == 0) ans = div + 1;
    else ans = div + 2;
    
    cout << ans;

}