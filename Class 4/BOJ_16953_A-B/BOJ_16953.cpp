#include <iostream>
#include <queue>
using namespace std;

long long A, B;

int bfs(){
    int cnt = 0;
    queue<long long> q;
    q.push(A);

    while(!q.empty()){
        cnt++;
        int size = q.size();
        for(int i = 0; i < size; i++){
            long long num = q.front(); q.pop();
            if(num == B) return cnt;
            long long x = num << 1;
            if(x <= B) q.push(x);
            long long y = num * 10 + 1;
            if(y <= B) q.push(y);
        }
    }
    return -1;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

   
    cin >> A >> B;
    cout << bfs();
}