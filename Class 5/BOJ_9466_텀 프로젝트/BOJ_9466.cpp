#include <iostream>
using namespace std;

int T, N;
int student[100001];
int visited[100001];
bool finished[100001];
int order;
int cnt;

void init(){
    order = 0;
    cnt = 0;
    for(int i = 1; i <= N; i++){
        student[i] = 0;
        visited[i] = 0;
        finished[i] = false;
    }
}

void dfs(int parent){
    visited[parent] = ++order;

    int child = student[parent];
    if(visited[child] == 0)
        dfs(child);
    else if(!finished[child])
        cnt += visited[parent] - visited[child] + 1;

    finished[parent] = true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    
    for(int t = 0; t < T; t++){
        cin >> N;
        init();
        for(int i = 1; i <= N; i++)
            cin >> student[i];

        for(int i = 1; i <= N; i++)
            if(!finished[i]) dfs(i);
        
        cout << N - cnt << '\n';
    }
}