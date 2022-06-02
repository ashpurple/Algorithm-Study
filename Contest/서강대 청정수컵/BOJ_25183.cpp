#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    string str;
    cin >> str;

    int cnt = 1;
    int maxCnt = 1;
    for(int i = 0; i < N - 1; i++){
        if(abs(str[i] - str[i + 1]) == 1){
            maxCnt = max(maxCnt, ++cnt);
        }
        else cnt = 1;
    }

    if(maxCnt >= 5) cout << "YES";
    else cout << "NO";
}