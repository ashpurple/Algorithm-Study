#include <iostream>
#include <vector>
using namespace std;

vector<int> v; // 주어진 원소
vector<int> result; // 출력할 순열
int m; // 출력할 순열의 길이
bool visited[9]; // 방문여부 체크 

void dfs() { // nPm
	if (result.size() == m) {
		for (int i : result) 
			cout << i << " ";
		
		cout << "\n";
        return;
	}
	for (int i = 0; i < v.size(); i++) {
		if (!visited[i]) {
			visited[i] = true;
			result.push_back(v[i]);
			dfs();
			result.pop_back();
			visited[i] = false;
		}
	}
}

void dfs() { // nΠm
	if (result.size() == m) {
		for (int i : result) 
			cout << i << " ";
		
		cout << "\n";
        return;
	}
	for (int i = 0; i < v.size(); i++) {
		result.push_back(v[i]);
		dfs();
		result.pop_back();
	}
}