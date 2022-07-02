#include <string>
#include <vector>
#include <queue>
using namespace std;
struct Data{
  int w; int sec;  
};
queue<Data> q;
queue<int> truckQ;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int total = 0;
    int time = 0;
    for(int truck : truck_weights) truckQ.push(truck);
    while(true){
        if(!q.empty()){
            if(time - q.front().sec >= bridge_length){
                total -= q.front().w;
                q.pop();
            }
        }
        if(!truckQ.empty()){
            int truck = truckQ.front();
            if(total + truck <= weight && q.size() + 1 <= bridge_length){
                total += truck;
                q.push({truck, time});
                truckQ.pop();
            }
        }
        time++;
        if(q.empty()) break;
    }
    
    answer = time;
    
    return answer;
}