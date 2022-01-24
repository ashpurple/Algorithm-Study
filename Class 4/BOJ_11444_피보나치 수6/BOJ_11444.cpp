#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

long long N;

vector<vector<long long>> multiply(vector<vector<long long>> &a, vector<vector<long long>> &b){
    vector<vector<long long>> temp(2, vector<long long>(2));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                temp[i][j] += a[i][k] * b[k][j];
            }
            temp[i][j] %= MOD;
        }
    }
    return temp;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    vector<vector<long long>> mat = {{1, 1}, {1, 0}};
    vector<vector<long long>> result = {{0, 1},{1, 0}};

    while(0 < N){
        if(N & 1) // odd
            result = multiply(mat, result);
        mat = multiply(mat, mat);
        N >>= 1;
    }

    cout << result[0][0];
}