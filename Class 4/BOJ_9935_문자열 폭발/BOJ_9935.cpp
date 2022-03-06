#include <iostream>
using namespace std;

string str, bomb;
bool flag;
char ans[1000001];
int strLen, bombLen, bombSize;

void check(int idx){
    flag = false;
    for(int j = idx - 1; j >= idx - bombLen; j--){
        if(ans[j] == bomb[bombSize--]) flag = true;
        else{
            flag = false;
            break;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> str >> bomb;
    strLen = str.length();
    bombLen = bomb.length();
    int idx = 0;
    for(int i = 0; i < strLen; i++){
        ans[idx++] = str[i];
        bombSize = bombLen;
        if(str[i] == bomb[--bombSize]){
            check(idx);
            if(flag) idx -= bomb.length();
        }
    }
 
    if(idx == 0) cout << "FRULA" << '\n';
    
    else{
        for(int i = 0; i < idx; i++) cout << ans[i];
        cout << '\n';
    }

}