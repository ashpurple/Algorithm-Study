#include <iostream>
#include <queue>
using namespace std;

int N;
string a, b;
int alphaCnt[26];
char vowel[5] = {'a','e','i','o','u'};

bool isVowel(char ch){
    for(int j = 0; j < 5; j++){
        if(ch == vowel[j]) return true;
    }
    return false;
}

bool check(){
    // rule 2
    if(a[0] != b[0] || a[N - 1] != b[N - 1]) return false;
    // rule 1
    for(int i = 0; i < N; i++){
        alphaCnt[a[i] - 'a']++;
        alphaCnt[b[i] - 'a']--;
    }
    for(int i = 0; i < 26; i++){
        if(alphaCnt[i] != 0) return false;
    }
    // rule 3
    queue <int> word;
    for(int i = 0; i < N; i++){
        if(!isVowel(a[i])) word.push(a[i]);
    }
    for(int i = 0; i < N; i++){
        if(!isVowel(b[i])){
            if(word.front() == b[i]) word.pop();
            else return false;
        }
    }
    
    return true;
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> a >> b;
    if(check()) cout << "YES";
    else cout << "NO";
}