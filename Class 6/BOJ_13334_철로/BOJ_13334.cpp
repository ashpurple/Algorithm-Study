#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct Rail{
    int a;
    int b;
    bool operator<(const Rail p) const{
        if(b == p.b) return a > p.a;
        return b > p.b;
    }
};
struct Start{
    int a;
    bool operator<(const Start p) const{
        return a > p.a;
    }
};

int N, D;
priority_queue<Rail> pq;
priority_queue<Start> spq;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int a, b;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        if(a > b) swap(a, b);
        pq.push({a, b});
    }
    cin >> D;
    
    int cnt = 0;

    while(!pq.empty()){
        Rail rail = pq.top();
        pq.pop();
        if(rail.b - rail.a <= D) spq.push({rail.a});
        
        while(!spq.empty() && D < rail.b - spq.top().a)
            spq.pop();

        int size = spq.size();
        cnt = max(cnt, size);    
    }
    cout << cnt;
}