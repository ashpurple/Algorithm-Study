#include <iostream>
using namespace std;

int r, c, result;
void divide(int, int, int);

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N >> r >> c;

    divide(0, 0, (1 << N));
}

void divide(int row, int col, int size){
    if(row == r && col == c){
        cout << result;
        return;
    }
    
    if(r < row + size && r >= row  && c < col + size && c >= col){ // in range
        divide(row, col, size >> 1);
        divide(row, col + (size >> 1), size >> 1);
        divide(row + (size >> 1), col, size >> 1);
        divide(row + (size >> 1), col + (size >> 1), size >> 1);
    }
    else{ // out of range
        result += size * size;
    }
}