#include <iostream>
#include <queue>
using namespace std;

int N;
int dp[1000001];
bool cache[1000001][2];

int operation(){
    dp[1] = 0;
    for(int i = 2; i <= N; i++){
        dp[i] = dp[i - 1] + 1;

        if(i % 3 == 0){
            if(dp[i / 3] + 1 < dp[i]){
                dp[i] = dp[i / 3] + 1;
                cache[i][1] = true;
            }
        }
            
        if(i % 2 == 0){
            if(dp[i / 2] + 1 < dp[i]){
                dp[i] = dp[i / 2] + 1;
                cache[i][0] = true;
            }
        }
    }
    return dp[N];
}

void backTracking(){
    int num = N;
    queue <int> q;
    q.push(num);
    while(num != 1){
        
        if(cache[num][0]) num /= 2;
        else if(cache[num][1]) num /= 3;
        else num -=1;
   
        q.push(num);
    }

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cout << operation() << '\n';
    backTracking();
}

