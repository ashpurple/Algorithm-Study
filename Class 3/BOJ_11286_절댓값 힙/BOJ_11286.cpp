#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;

    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;

    while(N--){
        int num;
        cin >> num;
        if(num == 0){
            if(min_pq.empty() && max_pq.empty()) cout << 0 << '\n';
            else if(min_pq.empty()){
                cout << max_pq.top() << '\n';
                max_pq.pop();
            }
            else if(max_pq.empty()){
                cout << min_pq.top() << '\n';
                min_pq.pop();
            }
            else{
                int max = max_pq.top() * - 1;
                int min = min_pq.top();
                if(max <= min){
                    cout << max * -1 << '\n';
                    max_pq.pop();
                }
                else{
                    cout << min << '\n';
                    min_pq.pop();
                }
            }

        }
        else{
            if(num > 0) min_pq.push(num);
            if(num < 0) max_pq.push(num);
        }
    }

}