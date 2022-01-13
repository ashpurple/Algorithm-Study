#include <iostream>
using namespace std;

int matrix[1025][1025];
int dp[1025][1025] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int x1, y1, x2, y2, sum;

    cin >> N >> M;
    for(int i = 1; i < N + 1; i++){
        for(int j = 1; j < N + 1; j++){
            cin >> matrix[i][j];
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i][j];
        }
    }

    for(int i = 0; i < M; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        sum = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
        cout << sum << '\n';
    }
    
}