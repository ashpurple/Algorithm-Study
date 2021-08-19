#include <iostream>
#include <algorithm>
using namespace std;

int N;
int dp[1000];
int arr[1000];
int lis();

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    cout << lis();
   
}

int lis(){
    for (int i = 0; i < N; i++){
        dp[i] = 1;
		for (int j = 0; j < i; j++){
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1){
				dp[i] = dp[j] + 1;
			}
		}
	}
    int max = *max_element(dp, dp + N);
    return max;
}