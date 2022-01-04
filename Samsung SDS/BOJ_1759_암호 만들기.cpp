#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
vector<char> con;
vector<char> vow;
vector<char> word;
vector<char> result;

void dfs(int start) { // nCm
	if (result.size() == L) {
        int vowCnt = 0;
        int conCnt = 0;
        for (char i : result){
            if(i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u')
                vowCnt++;
            else
                conCnt++;
        }

        if(vowCnt >= 1 && conCnt >= 2){
            for (char i : result) 
                cout << i;
            cout << "\n";
        }
        return;
	}
	for (int i = start; i < word.size(); i++) {
        result.push_back(word[i]);
        dfs(i + 1);
        result.pop_back();
	}
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> L >> C;

    for(int i = 0; i < C; i++){
        char input;
        cin >> input;

        word.push_back(input);
    }
    sort(word.begin(), word.end());
    dfs(0);
}

