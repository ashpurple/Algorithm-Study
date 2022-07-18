#include<iostream>
using namespace std;
bool arr[10];
int num, ans;
bool check(){
    for(int i = 0; i < 10; i++){
        if(arr[i] == false) return true;
    }
    return false;
}

int main(int argc, char** argv){
	int T, t, N;

	cin >> T;
	for(t = 1; t <= T; t++){
        cin >> N;

        for(int i = 0; i < 10; i++) arr[i] = false;
        
        int cnt = 1;
        while(check()){
            num = N * cnt++;
            ans = num;
            while(num){
                arr[num % 10] = true;
                num /= 10;
            }
        }
        cout << "#" << t << ' ' << ans << '\n';

	}
	return 0;
}