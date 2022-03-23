#include <iostream>
using namespace std;
int T, k, n;
int apart[15][15];

void set(){
    for(int i = 1; i < 15; i++) apart[0][i] = i;

    for(int i = 1; i < 15; i++){
        for(int j = 1; j < 15; j++){
            apart[i][j] = apart[i][j - 1] + apart[i - 1][j];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    set();

    cin >> T;
    for(int t = 0; t < T; t++){
        cin >> k >> n;
        cout << apart[k][n] << '\n';
    }

}