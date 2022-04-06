#include <iostream>
#include <algorithm>
using namespace std;
int K, N;
long long lan[10000];

long long count(long long size){
    long long cnt = 0;
    for(int i = 0; i < K; i++){
        cnt += lan[i] / size;
    }
    //cout << size << " " << cnt << '\n';
    return cnt;
}

int binarySearch(long long start, long long end) {
    long long mid, cnt;
	while (start <= end) {
		mid = (start + end) / 2;
        cnt = count(mid);
		if (cnt < N) 
			end = mid - 1;
		else 
			start = mid + 1;
	}
	return end;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> K >> N;
    for(int i = 0; i < K; i++){
        cin >> lan[i];
    }

    sort(lan, lan + K);

    cout << binarySearch(1, lan[K - 1]);
}