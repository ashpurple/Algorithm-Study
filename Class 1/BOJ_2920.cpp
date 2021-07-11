#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cur, cnt = 0;
    string result;

    for(int i = 1; i < 9; i++){
        cin >> cur;
        if(cur == i)
            cnt++;
        else if(cur == 9 - i)
            cnt--;
    }
    if(cnt == 8)
        result = "ascending";
    else if(cnt == -8)
        result = "descending";
    else{
        result = "mixed";
    }
    cout << result;
}