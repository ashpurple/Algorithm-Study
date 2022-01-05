#include <iostream>
#include <algorithm>
using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K, M;
    int num[1000000];

    cin >> N >> K >> M;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
	}
    for (int i = 0; i < M + K; i++) {
        int op, a, b;
        cin >> op >> a >> b;
	}

}