#include <iostream>
#include <string>
using namespace std;

string str1, str2;
int dp[4001][4001] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int max = 0;
    cin >> str1 >> str2;
    for(int i = 1; i <= str1.size(); i++){
        for(int j = 1; j <= str2.size(); j++){
            if(str1[i - 1] == str2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if(max < dp[i][j])
                    max = dp[i][j];
            }
        }
    }
    cout << max;
}