#include <string>
#include <vector>
#include <set>
using namespace std;

set<string> s;

bool startswith(string a, string b){
    if(a.length() > b.length()) return false;
    for(int i = 0; i < a.length(); i++){
        if(a[i] != b[i]) return false;
    }
    return true;
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    for(string str: phone_book){
        s.insert(str);
    }
    
    for(auto iter = s.begin(); iter != s.end();){
        string now = *iter;
        iter++;
        string next = *iter;
        if(startswith(now, next)){
            answer = false;
            break;
        }
    }
    return answer;
}