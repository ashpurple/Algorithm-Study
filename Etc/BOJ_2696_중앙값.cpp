#include <iostream>
#include <queue>
using namespace std;

int T, N;
int num[9999];
vector<int> res;

void getMid(){
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    queue<int> temp;
    res.clear();
    
    int mid = num[0];
    res.push_back(mid);

    for(int i = 1; i < N; i++){
        if(mid > num[i]) maxHeap.push(num[i]);
        else minHeap.push(num[i]);

        if(!(i & 1)){ // odd
            if(maxHeap.size() < minHeap.size()){
                maxHeap.push(mid);
                mid = minHeap.top();
                minHeap.pop();
            }
            if(maxHeap.size() > minHeap.size()){
                minHeap.push(mid);
                mid = maxHeap.top();
                maxHeap.pop();
            }
            res.push_back(mid);
        }
    }
}

int main(){
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int t = 0; t < T; t++){
        cin >> N;
        for(int i = 0; i < N; i++)
            cin >> num[i];
        getMid();
        cout << res.size() << '\n';
        int cnt = 0;
        for(int i = 0; i < res.size(); i++){
            cout << res[i] << ' ';
            if(i % 10 == 9) cout << '\n';
        }
        cout << '\n';
    }
}