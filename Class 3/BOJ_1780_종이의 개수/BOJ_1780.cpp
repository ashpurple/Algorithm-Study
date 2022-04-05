#include <iostream>
using namespace std;
const int SIZE = 3*3*3*3*3*3*3;
int N;
int cnt[3];
int mat[SIZE][SIZE];

void divide(int r, int c, int size){
    if(size == 1){
        cnt[mat[r][c] + 1]++;
        return;
    }
    int num;
    bool flag = false;

    /* check */
    for(int i = r; i < r + size; i++){
        for(int j = c; j < c + size; j++){
            if(i == r && j == c) // first
                num = mat[i][j];
            if(mat[i][j] != num){
                flag = true;
                break;
            }
        }
    }

    if(flag){
        int n_size = size / 3;
        divide(r, c, n_size);
        divide(r + n_size, c, n_size);
        divide(r + n_size + n_size, c, n_size);
        divide(r, c + n_size, n_size);
        divide(r + n_size, c + n_size, n_size);
        divide(r + n_size + n_size, c + n_size, n_size);
        divide(r, c + n_size + n_size, n_size);
        divide(r + n_size, c + n_size + n_size, n_size);
        divide(r + n_size + n_size, c + n_size + n_size, n_size);
    }
    else{
        cnt[mat[r][c] + 1]++;
        return;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            cin >> mat[i][j];
    }
    divide(0, 0, N);
    cout << cnt[0] << '\n' << cnt[1] << '\n' << cnt[2];

}