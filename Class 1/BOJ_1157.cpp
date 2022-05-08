#include<iostream>
#include<algorithm>
using namespace std;
int alphabet[26];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    cin >> input;
    
    for(char ch : input){
        if('a' <= ch && ch <= 'z') alphabet[ch- 'a']++;
        if('A' <= ch && ch <= 'Z') alphabet[ch- 'A']++;
    }
    int ans = 0;
    int idx;
    bool flag = false;
    for(int i = 0; i < 26; i++){
        if(ans == alphabet[i]) flag = true;
        if(ans < alphabet[i]){
            ans = alphabet[i];
            flag = false;
            idx = i;
        }
    }
    if(flag) cout << '?';
    else {
        char ans = idx + 'A';
        cout << ans;
    }

}