#include <iostream>
#include <algorithm>
using namespace std;

bool compare(pair<int, int>, pair<int, int>);

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N , cnt = 0;
    cin >> N;

    pair<int, int> *p = new pair<int, int>[N];

    for(int i = 0; i < N; i++){
        cin >> p[i].first >> p[i].second;
    }

    sort(p, p + N, compare);

    int endTime = -1;
    for(int i = 0; i < N; i++){
        if(endTime <= p[i].first){
            endTime = p[i].second;
            cnt++;
        }
    }
    cout << cnt;
}

bool compare(pair<int, int>a, pair<int, int>b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	else {
		return a.second < b.second;
	}
}