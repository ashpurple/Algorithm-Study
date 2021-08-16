#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v; // 주어진 원소
vector<int> result; // 출력할 순열
int N, M;
bool visited[9]; // 방문여부 체크 
void dfs();

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    dfs();
}

void dfs() {
	if (result.size() == M) {
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
