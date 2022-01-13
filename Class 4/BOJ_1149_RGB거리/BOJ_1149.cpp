#include <iostream>
using namespace std;

int RGB[1001][3];
int dp[1001][3] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int r, g, b;

    cin >> N;
    for(int i = 1; i < N + 1; i++){
        for(int j = 0; j < 3; j++){
            cin >> RGB[i][j];

            if(j == 0){
                dp[i][j] = min(dp[i - 1][1], dp[i - 1][2]) + RGB[i][j];
            }
            else if(j == 1){
                dp[i][j] = min(dp[i - 1][0], dp[i - 1][2]) + RGB[i][j];
            }
            else if(j == 2){
                dp[i][j] = min(dp[i - 1][0], dp[i - 1][1]) + RGB[i][j];
            }
        }
    }

    cout << min(dp[N][0], min(dp[N][1], dp[N][2]));
}