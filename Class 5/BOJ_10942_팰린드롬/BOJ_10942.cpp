#include <iostream>
using namespace std;

int N, M;
int num[2001];
bool dp[2001][2001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    
    for(int i = 1; i <= N; i++)
        cin >> num[i];
    
    /* init  */
    for(int i = 1; i <= N; i++)
        dp[i][i] = true;

    for(int i = 1; i <= N -1; i++){
        if(num[i] == num[i + 1])
            dp[i][i + 1] = true;
    }
    
    /* DP */
    for(int i = N - 1; 1 <= i; i--){
        for(int j = i + 2; j <= N; j++){
            if(num[i] == num[j] && dp[i + 1][j - 1])
                dp[i][j] = true;
        }
    }

    cin >> M;
    int a, b;
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        cout << dp[a][b] << '\n';
    }
}