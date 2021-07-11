#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
	cin >> N >> K;
	queue<int> circular;
	for (int i = 0; i < N; i++) {
		circular.push(i + 1);
	}

	cout << "<";
	while (circular.size() - 1) {
		for (int i = 0; i < K - 1; i++) {
			circular.push(circular.front());
			circular.pop();
		}
		cout << circular.front() << ", ";
		circular.pop();
	}
	cout << circular.front() << ">";
}