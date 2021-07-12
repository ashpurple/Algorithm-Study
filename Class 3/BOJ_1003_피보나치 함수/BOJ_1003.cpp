#include <iostream>
using namespace std;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num, N;
    int dp[41] = {0, 1};
    cin >> num;
    

    for(int i = 2; i < 41; i++) 
        dp[i] = dp[i - 1] + dp[i - 2]; // 점화식

    for(int i = 0; i < num; i++){
        cin >> N;
        if(N == 0){
            cout << 1 << ' ' << 0 << '\n';
        } else{
        cout << dp[N - 1] << ' ' << dp[N] << '\n';
        }
    }

}
