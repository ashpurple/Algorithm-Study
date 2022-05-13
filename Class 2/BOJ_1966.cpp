#include <iostream>
#include <queue>
using namespace std;

struct Info{
    int val;
    bool target;
};

int T;
int N, M;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--){
        cin >> N >> M;
        priority_queue <int> pq;
        queue <Info> q;
        int target;
        for(int i = 0; i < N; i++){
            int num;
            cin >> num;
            if(i == M) q.push({num, true});
            else q.push({num, false});
            pq.push(num);
        }

        int cnt = 0;
        while(!q.empty()){
            Info front = q.front();
            if(pq.top() == front.val){
                if(front.target){
                    cout << cnt + 1 << '\n';
                    break;
                }
                q.pop(); pq.pop(); cnt++;
            }
            else{
                q.pop(); q.push(front);
            }
        }
    }
}