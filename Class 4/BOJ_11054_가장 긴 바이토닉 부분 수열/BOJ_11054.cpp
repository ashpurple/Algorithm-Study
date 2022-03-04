#include <iostream>
using namespace std;
int N;
int num[1000];
int dpFront[1000];
int dpBack[1000];
int dp[1000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> num[i];

    for(int i = 0; i < N; i++){
        dpFront[i] = 1;
        for(int j = 0; j < i; j++){
            if(num[j] < num[i] && dpFront[i] < dpFront[j] + 1)
                dpFront[i] = dpFront[j] + 1;
        }
    }
    for(int i = N - 1; 0 <= i; i--){
        dpBack[i] = 1;
        for(int j = N - 1; i < j; j--){
            if(num[j] < num[i] && dpBack[i] < dpBack[j] + 1)
                dpBack[i] = dpBack[j] + 1;
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        dp[i] = dpFront[i] + dpBack[i] - 1;
        ans = max(ans, dp[i]);
    }
    cout << ans;
}