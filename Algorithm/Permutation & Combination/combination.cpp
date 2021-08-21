#include <iostream>
#include <vector>
using namespace std;

vector<int> v; // 주어진 원소
vector<int> result; // 출력할 조합
int m; // 출력할 조합의 길이

void dfs(int start) { // nCm
	if (result.size() == m) {
		for (int i : result) 
			cout << i << " ";
		cout << "\n";
        return;
	}
	for (int i = start; i < v.size(); i++) {
        result.push_back(v[i]);
        dfs(i + 1);
        result.pop_back();
	}
}

void dfs(int start) { // nHm
	if (result.size() == m) {
		for (int i : result) 
			cout << i << " ";
		cout << "\n";
        return;
	}
	for (int i = start; i < v.size(); i++) {
        result.push_back(v[i]);
        dfs(i);
        result.pop_back();
	}
}