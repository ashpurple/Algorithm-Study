#include <iostream>
#include <string>
#include <vector>
using namespace std;

string str1, str2;
int length = 0;
int dp[4001][4001] = {0}; // size + 1
vector <char> result;

void lcs(){ // Longest Common Substring (최장 공통 문자열)
    for(int i = 1; i <= str1.size(); i++){
        for(int j = 1; j <= str2.size(); j++){
            if(str1[i - 1] == str2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1; // 왼쪽 대각선 + 1
            }
        }
    }
}

void LCS(){ // Longest Common Subsequence (최장 공통 부분 수열)
    for(int i = 1; i <= str1.size(); i++){
        for(int j = 1; j <= str2.size(); j++){
            if(str1[i - 1] == str2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1; // 왼쪽 대각선 + 1
            } 
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // 왼쪽, 위 중 큰 값
            }
            if(length < dp[i][j])
                length = dp[i][j];
        }
    }
}

void printLCS(){ // Print LCS Substring
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

    if(length > 0){
        while(!result.empty()){
            cout << str1[result.back() - 1];
            result.pop_back();
        }
    } 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> str1 >> str2;

    /* Longest Common Substring*/
    lcs();
    
    /* Longest Common Subsequence*/
    LCS();
    printLCS(); 
}