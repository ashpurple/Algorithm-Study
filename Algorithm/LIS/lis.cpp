#include <algorithm>
using namespace std;

int dp[5];
int arr[5];
int N = 5;

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