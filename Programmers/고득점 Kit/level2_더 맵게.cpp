#include <string>
#include <vector>
#include <queue>
using namespace std;

priority_queue <int, vector<int>, greater<int>> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    for(int num : scoville){
        pq.push(num);
    }
    
    while(true){
        int first = pq.top(); pq.pop();
        if(first >= K) break;
        if(pq.empty()){
            answer = -1; break;
        }
        int second = pq.top(); pq.pop();
        int mix = first + (second * 2);
        pq.push(mix);
        answer++;
    }
    
    return answer;
}