#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;
vector <int> result;
int row, col;
int cnt;
vector<int> candi;

bool isValid(vector<vector<string>> &vec){
    set <string> s;
    for(int i = 0; i < row; i++){
        int num = 0;
        string str = "";
        for(int j : result){
            string temp = vec[i][j];
            str += temp;
        }
        if(s.find(str) == s.end()) s.insert(str);
        else return false;
    }
    return true;
}

void dfs(int start, int m, vector<vector<string>> &vec) {
	if (result.size() == m) {
		if(!isValid(vec)) return;
        
        int bitset = 0;
        for(int c : result){
            int bit = 1 << c;
            bitset |= bit;
        }
        
        for(int candibit: candi){
            int comp = candibit & bitset;
            cout << "cd " <<candibit << ' ' << comp << '\n';
            if(comp == candibit) return;
        } 
        
        for(int c : result){
            cout << c << ' ';
        }
        cout << '\n';
        
        cout << bitset << '\n';
        candi.push_back(bitset);
        cnt++;
        
        return;
	}
	for (int i = start; i < col; i++) {
        result.push_back(i);
        dfs(i + 1, m, vec);
        result.pop_back();
	}
}

int solution(vector<vector<string>> relation) {
    row = relation.size();
    col = relation[0].size();
    for(int i = 1; i <= col; i++){
        dfs(0, i, relation);
        result.clear();
    }
    return cnt;
}