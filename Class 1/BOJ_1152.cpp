#include <iostream>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string word;
    getline(cin, word);
    int cnt = 1;
    
    for(int i = 0; i < word.length(); i++){
        if(i == 0 || i == word.length() - 1) continue;
        if(word[i] == ' ')
            cnt++;
    }
    if(word.empty()) cnt = 0;
    if(word.length() == 1 && word[0] == ' ') cnt = 0;
    cout << cnt;
}