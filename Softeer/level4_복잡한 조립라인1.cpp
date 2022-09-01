#include<iostream>
using namespace std;
int N, K;
const int SIZE = 100;
int work[SIZE][SIZE];
int moves[SIZE][SIZE][SIZE];// 층, start, end
int dp[SIZE][SIZE];
int MAX = 1987654321;

int main(int argc, char** argv){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K >> N;
    for(int i = 0; i < N - 1; i++){
        for(int j = 0; j < K; j++) cin >> work[i][j];
		for(int start = 0; start < K; start++){
            for(int end = 0; end < K; end++){
                if(start == end) continue;
                cin >> moves[i][start][end];
            }
        }
    }
    for(int j = 0; j < K; j++) cin >> work[N - 1][j];

    for(int j = 0; j < K; j++) dp[0][j] = work[0][j];

    for(int time = 0; time < N - 1; time++){
		for(int line = 0; line < K; line++){
            int minValue = MAX;
			for(int i = 0; i < K; i++){
                if(i == line) continue;
                minValue = min(minValue, moves[time][i][line] + dp[time][i]);
            }
            dp[time + 1][line] = min(dp[time][line], minValue) + work[time + 1][line];
		}
    }

    int ans = MAX;
    for(int i = 0; i < K; i++) ans = min(ans, dp[N - 1][i]);

    cout << ans;
    return 0;
}