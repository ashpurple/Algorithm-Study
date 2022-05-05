#include <iostream>
using namespace std;
int num, M, N, X, Y, j;

int gcd(int a, int b) {
    while (b) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> num;
    
    for(int i = 0; i < num; i++){
        cin >> M >> N >> X >> Y;
        int end = lcm(M, N);
        for(j = X; j <= end; j += M){
            int temp;
            if(j % N == 0) temp = N;
            else temp = j % N;
            if(temp == Y){
                cout << j << '\n';
                break;
            }
        }
        if(j > end) cout << -1 << '\n';
    }
}