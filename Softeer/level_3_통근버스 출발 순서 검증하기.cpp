#include <iostream>
using namespace std;
int N;
long long arr[5000];
long long cnt;

long long count(){
    long long ans = 0;
    for(int i = 0; i < N; i++){
        long long count = 0;
        for(int j = i + 1; j < N; j++){
            if(arr[i] < arr[j]) count++;
            else ans += count;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    cout << count();
}