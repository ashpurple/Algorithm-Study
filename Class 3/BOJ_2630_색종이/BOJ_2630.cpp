#include <iostream>
using namespace std;

int matrix[128][128];
int white = 0, blue = 0;
void divideMatrix(int, int, int);

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> matrix[i][j];
        }
    }
    divideMatrix(0, 0, N);

    cout << white << '\n' << blue;

}

void divideMatrix(int row, int col, int size){
    int prev = matrix[row][col];
    for(int i = row; i < row + size; i++){
        for(int j = col; j < col + size; j++){
            if(prev != matrix[i][j]){ // if different
                size = size >> 1;
                divideMatrix(row, col, size);
                divideMatrix(row, col + size, size);
                divideMatrix(row + size, col, size);
                divideMatrix(row + size, col + size, size);
                return;
            }
                
        }
    }
    if(prev)
        blue++;
    else
        white++;
}