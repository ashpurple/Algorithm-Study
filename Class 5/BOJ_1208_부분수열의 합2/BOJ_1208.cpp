#include<iostream>
#include<map>
using namespace std;

int N, S, half;
int num[40];
map<int, int> mp;
long long cnt;

void left(int idx, int sum){
	if(idx == half){
		mp[sum]++;
		return;
	}
	left(idx + 1, sum);
	left(idx + 1, sum + num[idx]);
}

void right(int idx, int sum){
	if(idx == N){
		cnt += mp[S - sum];
		return;
	}
	right(idx + 1, sum);
	right(idx + 1, sum + num[idx]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	cin >> N >> S;
	half = N >> 1;
	for (int i = 0; i < N; i++) cin >> num[i];

	left(0, 0);
	right(half, 0);

	if(S == 0) cnt--;
	cout << cnt;
}