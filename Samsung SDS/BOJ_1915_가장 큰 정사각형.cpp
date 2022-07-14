#include <iostream>
using namespace std;

int N, M;
int arr[1001][1001];
int ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> M;

    for(int i = 1; i <= N; i++){
        string str;
        cin >> str;
        for(int j = 0; j < M; j++){
            arr[i][j + 1] = str[j] - '0';
        }
    }

    for(int i = 1; i <= N; i ++){
        for(int j = 1; j <= M; j++){
            if(arr[i][j] == 0) continue;
            arr[i][j] = min(min(arr[i - 1][j], arr[i][j - 1]), arr[i - 1][j - 1]) + 1;
            ans = max(arr[i][j], ans);
        }
    }

    cout << ans * ans << '\n';
}