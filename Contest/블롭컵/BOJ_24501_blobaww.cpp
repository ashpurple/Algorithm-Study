#include<iostream>
using namespace std;

int N, M;
char esm[3001][3001];
long long dp[3001][3001][3];

void makeDP(char ch, int idx){
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            dp[i][j][idx] += dp[i][j - 1][idx];
            if(esm[i][j] == ch){
                if(idx == 0) dp[i][j][idx]++;
                else dp[i][j][idx] += dp[i][j][idx - 1];
            }
        }
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
                dp[i][j][idx] += dp[i - 1][j][idx];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        string str;
        cin >> str;
        for(int j = 1; j <= M; j++){
            esm[i][j] = str[j - 1];
        }
    }
    makeDP('E', 0);
    makeDP('S', 1);
    makeDP('M', 2);
    cout << dp[N][M][2] % 1000000007;
}