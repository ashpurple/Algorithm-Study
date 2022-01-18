#include <iostream>
#include <queue>
#define MAX 100001
#define INF 987654321
using namespace std;

int N, K;
int dp[MAX];

int bfs(){
    queue<int> q;
    q.push(N);
    dp[N] = 0;

    while(true){
        int loc = q.front();
        q.pop();
        if(loc == K) return dp[loc];

        if(0 <= loc - 1 && dp[loc - 1] > dp[loc] + 1){
            q.push(loc - 1); // X - 1
            dp[loc - 1] = dp[loc] + 1;
        }
        if(loc + 1 < MAX && dp[loc + 1] > dp[loc] + 1){
            q.push(loc + 1); // X + 1
            dp[loc + 1] = dp[loc] + 1;
        }
        if((loc << 1) < MAX && dp[loc << 1] > dp[loc]){
            q.push(loc << 1); // X^2
            dp[loc << 1] = dp[loc];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    for (int i = 0; i < MAX; i++){
        dp[i] = INF;
    }

    int ans = bfs();
    cout << ans;
}