#include <iostream>
using namespace std;
int N;
int day[1000];
bool dp[1000][7];

void makeDP() {
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < 7; j++) {
            dp[i][day[i]] = true;
            if(i == 0) continue;
            
			if(dp[i - 1][j]){
                dp[i][j] = true;
                int idx = (day[i] + j) % 7;
                dp[i][idx] = true;
            }
		}
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> day[i];
        day[i] %= 7;
    }
    makeDP();
    if(dp[N - 1][4]) cout << "YES";
    else cout << "NO";
}