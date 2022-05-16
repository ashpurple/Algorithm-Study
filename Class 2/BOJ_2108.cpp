#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int N;
int arr[500000];
int num[10001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    int M, m;
    m = 4001;
    M = -4001;
    double sum = 0;
    double size = N;

    for(int i = 0; i < N; i++){
        cin >> arr[i];
        sum += arr[i];
        M = max(arr[i], M);
        m = min(arr[i], m);
        num[arr[i] + 4000]++;
    }

    int maxCnt = *max_element(num, num + 10000);
    int ans;
    int cnt = 0;

    for(int i = 0; i <= 8000; i++){
        if(cnt == 2) break;
        if(num[i] == maxCnt){
            ans = i - 4000;
            cnt++;
        }
    }
    sort(arr, arr + N);
    if(round(sum / size) == -0) cout << 0 << '\n';
    else cout << round(sum / size) << '\n';
    cout << arr[N / 2] << '\n';
    cout << ans << '\n';
    cout << M - m << '\n';

}