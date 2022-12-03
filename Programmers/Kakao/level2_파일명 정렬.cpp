#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iostream>
using namespace std;
struct Data{
    int idx;
    string head;
    string headLower;
    int num;
    string number;
    string tail;
    bool operator<(const Data d) const {
        if(headLower == d.headLower){
            if(num == d.num) return idx < d.idx;
            return num < d.num;
        }
        
        return headLower < d.headLower;
    }
};
vector<Data> v;

bool isNum(char ch){
    if('0' <= ch && ch <= '9') return true;
    return false;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    for(int i = 0; i < files.size(); i++){
        string str = files[i];
        int idx = 0, idx2 = 0;
        while(true){
            if(!isNum(str[idx])) idx++;
            else break;
        }
        // head
        string head = str.substr(0, idx);
        string headLower = "";
        for(char ch : head){
            headLower += tolower(ch);
        }
        // number
        idx2 = idx;
        while(true){
            if(isNum(str[idx2])) idx2++;
            else break;
        }
        string number = str.substr(idx, idx2 - idx);
        int num = stoi(number);
        // tail
        string tail = "";
        if(str.length() != idx2){
            tail = str.substr(idx2, str.length() - idx2);
        }
        // string
        v.push_back({i, head, headLower, num, number, tail});
    }
    sort(v.begin(), v.end());
    for(Data data: v){
        string file = "";
        file += data.head;
        file += data.number;
        file += data.tail;
        answer.push_back(file);
    }
    
    return answer;
}