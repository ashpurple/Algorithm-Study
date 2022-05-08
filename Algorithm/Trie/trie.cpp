#include<iostream>
using namespace std;

struct TRIE{
    bool finish;
    TRIE *node[26];
    TRIE() { 
        finish = false;  
        for (int i = 0; i < 26; i++) node[i] = NULL;
    }

    ~TRIE(){
        for (int i = 0; i < 26; i++){
            if(node[i]) delete node[i];
        }
    }

    void insert(char *str){
        if (*str == NULL){
            finish = true;
            return;
        }
        int cur = *str - 'A';
        if (node[cur] == NULL) node[cur] = new TRIE();
        node[cur]->insert(str + 1);
    }

    bool find(char *str){
        if (*str == NULL){
            if (finish == true) return true;
            return false;
        }
        int cur = *str - 'A';
        if (node[cur] == NULL) return false;
        return node[cur]->find(str + 1);
    }

};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


}