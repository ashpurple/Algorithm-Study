#include <iostream>
using namespace std;
#define INF 987654321
int input[100000];
int dp[100000][5][5];
int N;

int getCost(int cur, int next){
    if(cur == 0) return 2;
    else if(cur == next) return 1;
    else if(abs(cur - next) == 2) return 4;
    else return 3;
}

int dfs(int num, int l, int r){
    if(num == N) return 0; // end
    if(l == r && r != 0) return INF; // same loc
    if(dp[num][l][r] != 0) return dp[num][l][r]; // memoization

    int moveLeft = dfs(num + 1, input[num], r) + getCost(l, input[num]);
    int moveRight = dfs(num + 1, l, input[num]) + getCost(r ,input[num]);
    dp[num][l][r] = min(moveLeft, moveRight);
    return dp[num][l][r];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i = 0;
    do{ cin >> input[i];
    } while(input[i++] != 0);

    N = i - 1;
    cout << dfs(0, 0, 0);
}