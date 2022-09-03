#include<iostream>
using namespace std;
int N, T;
const int SIZE = 200000;
long long arr[SIZE];
long long high;
long long low;
long long ans;

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> T;
	for(int t = 0; t < T; t++){
		high = 0; low = 0;
		for(int i = 0; i < 2 * N - 1; i++){
			cin >> arr[i];
			if(i & 1){
                high = max(high, max(arr[i] + arr[i + 1], arr[i] + arr[i - 1]));
            }
		}
		
		while(low <= high){
			long long mid = (low + high) / 2;
			bool flag = true;
			long long temp = 0;
			for(int i = 1; i < 2 * N - 1; i += 2){
				long long num = temp + arr[i-1];
				if(num < mid){
					if(mid - num > arr[i]){
						flag = false;
						break;
					}
					else temp = arr[i] - (mid - num);
					
				}else{
					temp = arr[i];
				}
			}
			if(arr[2 * N - 2] + temp < mid) flag = false;
			if(flag){
				low = mid + 1;
				ans = mid;
			}
			else high = mid - 1;
		}
		cout << ans << '\n';

	}
	
	return 0;
}