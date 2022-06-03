#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int even = N / 2;
    int odd = even * 2;

    for(int i = 0; i < N; i++){
        
        if((i & 1) == 0){
            if(even == 0) cout << N;
            else cout << even << ' ';
            even--;
        }
        else{
            cout << odd << ' ';
            odd--;
        }
    }
}