#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, num;
    cin >> N >> num;
    for(int i = 0; i < N; i++){
        int x;
        cin >> x;
        if(x < num) cout << x << ' ';
    }
}