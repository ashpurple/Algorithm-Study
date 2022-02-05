#include <iostream>
using namespace std;
 
int N;
int mat[501][2], dp[501][501];

int multiply(int start, int mid, int end){
    return mat[start][0] * mat[mid][1] * mat[end][1];
}
 
int divide(int start,int end){

    if(start == end) return 0;
    if(dp[start][end] != 0) return dp[start][end]; // if has dp
    if(start + 1 == end) // two matrix
        return dp[start][end] = multiply(start, start, end);
    
    int result;
    for(int i = start; i < end; i++){ // 3 or more matrix
        result = divide(start,i) + divide(i+1,end) + multiply(start, i ,end);
        if(dp[start][end] == 0 || result < dp[start][end]) 
            dp[start][end] = result;
    }
    return dp[start][end];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> mat[i][0] >> mat[i][1];

    cout << divide(1, N);
}