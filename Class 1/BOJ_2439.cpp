#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for(int i = N; 0 < i; i--){
        for(int j = 1; j <= N; j++){
            if(i <= j) cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }
}