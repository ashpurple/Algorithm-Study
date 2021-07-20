#include <iostream>
using namespace std;

void makeDP(int);
int dp[11];

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;

        makeDP(num);
        cout << dp[num] << '\n';
    }
}

void makeDP(int num){
    for(int i = 4; i <= num; i++){
        if(dp[i] == 0)
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }
}
