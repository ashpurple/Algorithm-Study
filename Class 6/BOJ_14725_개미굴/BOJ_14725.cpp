#include <iostream>
#include <map>
#include <vector>
using namespace std;
 
int N, nextIdx;
map<string, int> trie[15001];

void insert(const vector<string>& v){
    int idx = 0;
    for(string str: v){
        if(trie[idx].find(str) == trie[idx].end()){ // not find
            trie[idx][str] = ++nextIdx;
            idx = nextIdx;
        }
        else{ // find
            idx = trie[idx][str];
        }
    }
}

void print(int idx, int depth){
    for(pair<string, int> p : trie[idx]){
        string str = p.first;
        int nextIdx = p.second;
        for(int i = 0; i < depth; i++) cout << "--";
        cout << str << '\n';
        print(nextIdx, depth + 1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cin >> N;
    for(int i = 0; i < N; i++){
        int idx;
        string str;
        vector<string> v;
        cin >> idx;
        for(int j = 0; j < idx; j++){
            cin >> str;
            v.push_back(str);
            insert(v);
        }
    }
    print(0, 0);
}
