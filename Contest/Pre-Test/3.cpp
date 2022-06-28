#include <iostream>
using namespace std;
int T, N;
long long wage[16];
long long ans;
int cnt[2][4];

void init(){
    ans = 1987654321;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 4; j++){
            cnt[i][j] = 0;
        }
    }
}
void add(int num){
    for(int i = 3; 0 <= i; i--){
        cnt[num & 1][i]++;
        num >>= 1;
    }
}
void sub(int num){
    for(int i = 3; 0 <= i; i--){
        cnt[num & 1][i]--;
        num >>= 1;
    }
}
bool isEnd(){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 4; j++){
            if(cnt[i][j] < N) return false;
        }
    }
    return true;
}

void combi(int start, long long sum) { // nCm
	if (isEnd()) {
		ans = min(ans, sum);
        return;
	}
	for (int i = start; i < 16; i++) {
        add(i);
        combi(i + 1, sum + wage[i]);
        sub(i);
	}
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int t = 1; t <= T; t++){
        cin >> N;
        for(int i = 0; i < 16; i++){
            cin >> wage[i];
        }
        init();
        combi(0, 0);
        cout << "#" << t << ' '<< ans << '\n';
    }
}