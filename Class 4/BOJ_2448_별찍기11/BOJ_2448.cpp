#include <iostream>
using namespace std;
int N;
char stars[3072][3072 * 2];

void divide(int r, int c, int num){
    if(num == 3){
        stars[r][c] = '*'; // (0,2)

        stars[r + 1][c - 1] = '*'; // (1,1)
        stars[r + 1][c + 1] = '*'; // (1,3)

        stars[r + 2][c - 2] = '*'; // (2,0)
        stars[r + 2][c - 1] = '*'; // (2,1)
        stars[r + 2][c] = '*'; // (2,2)
        stars[r + 2][c + 1] = '*'; // (2,3)
        stars[r + 2][c + 2] = '*'; // (2,4)
        return;
    }
    
    
    divide(r, c, num / 2);
    divide(r + (num / 2), c - (num / 2), num / 2);
    divide(r + (num / 2), c + (num / 2), num / 2);

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    // init
    int M = N * 2 - 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            stars[i][j] = ' ';
        }
    }

    divide(0, N - 1, N); // top star

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cout << stars[i][j];
        }
        cout << '\n';
    }
}