#include <iostream>
#include <queue>
using namespace std;
int N, K, cnt, timeCnt;
queue <int> q;
int visited[100001];
bool flag;

void bfs(){
    q.push(N);
    visited[N] = true;

    while(!flag){
        int cycle = q.size();
        for(int i = 0; i < cycle; i++){
            int num = q.front();
            q.pop();
            visited[num] = true;

            if(num == K){
                cnt++;
                flag = true;
            }
            
            if(num - 1 >= 0 && !visited[num - 1]) q.push(num - 1);
            
            if(num + 1 <= 100000 && !visited[num + 1]) q.push(num + 1);
            
            if(num * 2 <= 100000 && !visited[num * 2]) q.push(num * 2);
            
        }
        timeCnt++;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    bfs();
    cout << timeCnt - 1 << '\n' << cnt;
}