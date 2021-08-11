#include <iostream>
using namespace std;

void dfs(int, int);

bool visited[9] = {0, }; 
int num[9];
int N, M;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    dfs(1, 0);
}

void dfs(int start, int cnt){
    if(cnt == M){
        for(int i = 0; i < M; i++)
            cout<< num[i] << ' ';
        cout << '\n';
        return;
    }

	for (int i = start; i <= N; i++){
		if (!visited[i]){
            visited[i] = true;
            num[cnt] = i;
            dfs(i + 1, cnt + 1);
            visited[i] = false;
        }
	}
}