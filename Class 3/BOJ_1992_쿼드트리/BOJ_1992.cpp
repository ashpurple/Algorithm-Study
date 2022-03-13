#include <iostream>
using namespace std;

int N;
int mat[64][64];
string res ="";

void divide(int row, int col, int size){
    bool one = false;
    bool zero = false;
    
    for(int i = row; i < row + size; i++){
        for(int j = col; j < col + size; j++){
            if(mat[i][j]) one = true;
            else zero = true;
            if(one && zero){
                size >>= 1;
                res.push_back('(');
                divide(row, col, size);
                divide(row, col + size, size);
                divide(row + size, col, size);
                divide(row + size, col + size, size);
                res.push_back(')');
                return;
            }
        }
    }
    if(one) res.push_back('1');
    else res.push_back('0');
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        string input;
        cin >> input;
        for(int j = 0; j < N; j++)
            mat[i][j] = input[j] - '0';
    }
    divide(0, 0, N);
    cout << res;

}