#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    int N;
    long long r = 1, M = 1234567891;
    long long hash = 0;
    cin >> N;
    cin >> input;
	for(int i = 0; i < N; i++){
        long long num = input[i] - 'a' + 1;
        hash = hash + ((num * r) % M);
        hash %= M;
        r = (r * 31) % M;
    }
    cout << hash;
}