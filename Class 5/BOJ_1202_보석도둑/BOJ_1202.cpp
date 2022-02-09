#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
 
struct Jewelry{
    int m;
    int v;

    bool operator<(const Jewelry jew) const{
        return m < jew.m; // ascending
    }
} jewelry[300000];

int N, K;
int bag[300000];
priority_queue<int> pq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cin >> N >> K;
    for(int i = 0; i < N; i++) cin >> jewelry[i].m >> jewelry[i].v;
    for(int i = 0; i < K; i++) cin >> bag[i];

    sort(jewelry, jewelry + N);
    sort(bag, bag + K);

    long long sum = 0;
    int idx = 0;
    for(int i = 0; i < K; i++){
        for(int j = 0; j < N; j++){
            if(jewelry[idx].m <= bag[i]){ 
                pq.push(jewelry[idx].v);
                idx++;
            }
            else break;
        }
        if(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum;
}
