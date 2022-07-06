#include <iostream>
#include <queue>
using namespace std;
int N, num;
priority_queue <int> max_pq;
priority_queue <int, vector<int>, greater<int>> min_pq;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num;
        if(max_pq.size() >= min_pq.size() + 1) min_pq.push(num);
        else max_pq.push(num);
        
        if(!min_pq.empty()){
            int maxTop = max_pq.top();
            int minTop = min_pq.top();
            if(maxTop > minTop){
                max_pq.pop();
                min_pq.pop();
                max_pq.push(minTop);
                min_pq.push(maxTop);
            }
        }
        cout << max_pq.top() << '\n';
    }
}
