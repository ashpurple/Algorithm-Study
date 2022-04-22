#include <iostream>
using namespace std;

int convert(string num){
    int res = 0;
    res += num[0] - '0';
    res += (num[1] - '0') * 10;
    res += (num[2] - '0') * 100;
    return res;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;
    cin >> a >> b;

    int A = convert(a);
    int B = convert(b);
    if(A > B) cout << A;
    else cout << B;
}