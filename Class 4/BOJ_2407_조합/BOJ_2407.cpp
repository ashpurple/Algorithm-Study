#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
string dp[101][101];
string combination(int, int);
string addString(string, string);

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    cout << combination(N, M);
   
}

string combination(int n, int m){
    if (n == m || m == 0)
        return "1";

    if (dp[n][m] != "")
        return dp[n][m];

    // Pascal Triangle
    dp[n][m] = addString(combination(n - 1, m - 1), combination(n - 1, m));
    return dp[n][m];
}

string addString(string a, string b){
    int sum = 0;
    string result;

    while (!a.empty() || !b.empty() || sum){
        if (!a.empty()){
            sum += a.back() - '0';
            a.pop_back();
        }
        if (!b.empty()){
            sum += b.back() - '0';
            b.pop_back();
        }
        result.push_back((sum % 10) + '0');
        sum /= 10;
    }
    reverse(result.begin(), result.end());
    return result;
}