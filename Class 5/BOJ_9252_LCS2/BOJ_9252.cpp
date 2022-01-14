#include <iostream>
#include <vector>
#include <string>
using namespace std;

string str1, str2;
vector <char> result;
int dp[1001][1001] = {0};
int lcs_length = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str1 >> str2;

    // make dp
    for(int i = 1; i <= str1.size(); i++){
        for(int j = 1; j <= str2.size(); j++){
            if(str1[i - 1] == str2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } 
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            if(lcs_length < dp[i][j])
                lcs_length = dp[i][j];
        }
    }

    // find dp
    int i = str1.size();
    int j = str2.size();

    while (dp[i][j] != 0){
        // 테이블이 같은 넘버링이라면
        // 왼쪽으로 이동
        if (dp[i][j] == dp[i][j - 1])
            j--;
 
        // 위쪽으로 이동
        else if (dp[i][j] == dp[i - 1][j])
            i--;
 
        // 왼쪽 위쪽 모두 다른 넘버링이라면 대각선 방향으로 이동
        else if (dp[i][j] - 1 == dp[i - 1][j - 1])
        {
            result.push_back(i);
            i--;
            j--;
        }
    }

    if(lcs_length > 0){
        cout << lcs_length << '\n';
        while(!result.empty()){
            cout << str1[result.back() - 1];
            result.pop_back();
        }
        cout << '\n';
    } else{
        cout << 0;
    }
        
}