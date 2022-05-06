#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string input;
    int alphabet[26];
    cin >> input;

    for(int i = 0; i < 26; i++) alphabet[i] = -1;
    for(int i = 0; i < input.length(); i++){
        char ch = input[i];
        if(alphabet[ch - 'a'] == -1) alphabet[ch - 'a'] = i;
    }
    for(int loc : alphabet){
        cout << loc << ' ';
    }
}