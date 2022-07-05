#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long arr[4][4000];
long long cnt;
long long first, s, e;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < 4; j++)
            cin >> arr[j][i];

    vector<long long> second;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            second.push_back(arr[2][i] + arr[3][j]);

    sort(second.begin(), second.end());

    for(int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            first = arr[0][i] + arr[1][j];
            s = lower_bound(second.begin(), second.end(), -first) - second.begin();
            e = upper_bound(second.begin(), second.end(), -first) - second.begin();
            if (second[s] == -first) cnt += (e - s);
        }
    }
    cout << cnt << "\n";
}
