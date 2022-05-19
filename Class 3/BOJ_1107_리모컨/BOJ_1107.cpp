#include <iostream>
#include <string>
using namespace std;
int N, M;
bool broken[10];

bool isPossible(string str, int size) {
	for (int i = 0; i < size; i++) {
		if (broken[str[i] - '0'])
			return false;
	}
	return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < M; i++){
        int num;
        cin >> num;
        broken[num] = true;
    }
    
    if (N == 100) {
		cout << 0;
		return 0;
	}

    int ans = abs(N - 100);

	for (int i = 0; i <= 1000000; i++) {
        string str = to_string(i);
        int size = str.size();
		if (isPossible(str, size)) {
			int temp = abs(N - i) + size;
			ans = min(ans, temp);
		}
	}

	cout << ans;
}