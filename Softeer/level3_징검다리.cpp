#include<iostream>
#include<algorithm>
using namespace std;
const int SIZE = 3000;
int N;
int arr[SIZE];
int dp[SIZE];

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}

	for(int i = 0; i < N; i++){
        dp[i] = 1;
		for (int j = 0; j < i; j++){
			if (arr[j] < arr[i] && dp[i] <= dp[j]){
				dp[i] = dp[j] + 1;
			}
		}
	}
    int max = *max_element(dp, dp + N);
	cout << max;


	return 0;
}