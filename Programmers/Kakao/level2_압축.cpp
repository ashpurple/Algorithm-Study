#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> dict;

void init(){
    char ch = 'A';
    for(int i = 0; i < 26; i++){
        string str = "";
        str += (char)(ch + i);
        dict.push_back(str);
    }    
}

vector<int> solution(string msg) {
    vector<int> answer;
    init();
    
    int len = msg.length();
    for(int i = 0; i < len; i++){
        for(int cnt = len - i; 0 < cnt; cnt--){
            string w = msg.substr(i, cnt);
            auto it = find(dict.begin(), dict.end(), w);
            if(it != dict.end()){
                answer.push_back(it - dict.begin() + 1);
                if(i != len - 1){
                    dict.push_back(w + msg[i + cnt]);
                }
                i += (cnt - 1);
                break;
            }
        }
    }
    return answer;
}