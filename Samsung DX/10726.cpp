#include<iostream>
using namespace std;
string ans;

bool isValid(int num, int cnt){
    while(cnt--){
        if(!(num & 1)) return false;
        num >>= 1;
    }
    return true;
}

int main(int argc, char** argv){
	int T, t, N, M;

	cin >> T;
	for(t = 1; t <= T; t++){
        cin >> N >> M;
        
        if(isValid(M, N)) ans = "ON";
        else ans = "OFF";
        cout << "#" << t << ' ' << ans << '\n';

	}
	return 0;
}