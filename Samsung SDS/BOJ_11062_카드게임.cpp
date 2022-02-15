#include <iostream>
#include <cstring>
using namespace std;
#define INF 987654321
int card[1000];
int dp[1000][1000][2];
int T, N;


int dfs(int num, int l, int r){
    bool flag = !(num & 1); // 1 is player

    if(dp[l][r][flag] != 0) return dp[l][r][flag]; // memoization
    if(l == r){ // last
        if(flag)
            return card[l];
        return dp[l][r][flag] = 0;
    }

    int left = dfs(num + 1, l + 1, r);
    int right = dfs(num + 1, l, r - 1);

    if(flag){ // player
        left += card[l];
        right += card[r];
        dp[l][r][flag] = max(left, right);
    }
    else{ // other player
        dp[l][r][flag] = min(left, right); // opponent's min
    }
    

    return dp[l][r][flag];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int t = 0; t < T; t++){
        memset(dp, 0, sizeof(dp));
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> card[i];
        }
        cout << dfs(0, 0, N - 1) << '\n';
    }

}