#include <iostream>
#include <vector>
using namespace std;
char table[5][5];
string message;
string key;
string cypher = "";
vector <string> word;

int findIdx(char ch){
    int idx = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(table[i][j] == ch) return idx;
            idx++;
        }
    }
}

void makeTable(){
    char visited[26] = {false};
    visited[9] = true; // Skip J
    int idx = 0;
    for(char ch : key){
        int i = idx / 5;
        int j = idx % 5;
        if(visited[ch - 'A']) continue;
        table[i][j] = ch;
        visited[ch - 'A'] = true;
        idx++;
    }
    int k = 0;
    while(idx != 25){
        if(!visited[k]){
            int i = idx / 5;
            int j = idx % 5;
            char ch = k + 'A';
            table[i][j] = ch;
            idx++;
        }
        k++;
    }
}

void split(){
    int cnt = 0;
    string str = "";
    for(char ch : message){
        if(str.length() == 0) str += ch;
        else{ // length 1
            if(str[0] == ch){
                if(ch == 'X') str += 'Q';
                else str += 'X';
                word.push_back(str);
                str = ch;
            }
            else{
                str += ch;
                word.push_back(str);
                str = "";
            }
        }
    }
    if(str.length() == 1){
        str += 'X';
        word.push_back(str);
    }
}

void encode(){
    for(string str : word){
        int a = str[0];
        int b = str[1];
        int idxA = findIdx(a);
        int idxB = findIdx(b);
        int aR = idxA / 5;
        int aC = idxA % 5;
        int bR = idxB / 5;
        int bC = idxB % 5;
        if(aR == bR){
            aC = (aC + 1) % 5;
            bC = (bC + 1) % 5;
        }
        else if(aC == bC){
            aR = (aR + 1) % 5;
            bR = (bR + 1) % 5;
        }
        else{
            swap(aC, bC);
        }
        cypher += table[aR][aC];
        cypher += table[bR][bC];

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> message >> key;

    makeTable();
    split();
    encode();
    cout << cypher;
}