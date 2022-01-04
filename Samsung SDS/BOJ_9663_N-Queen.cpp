#include <iostream>
using namespace std;

int board[15];
int N;
int cnt = 0;

bool isValid(int n){
    for(int i = 0; i < n; i++){
        if(board[i] == board[n] || abs(board[n] - board[i]) == (n - i))
            return false;
    }
    return true;
}

void dfs(int depth){
    if(depth == N){
        cnt++;
    }
    for (int i = 0; i < N; i++){
        board[depth] = i;
        if (isValid(depth))
            dfs(depth + 1);
    }

}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    dfs(0);
    cout << cnt;
}

