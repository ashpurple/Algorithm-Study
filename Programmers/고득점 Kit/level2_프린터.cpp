#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct Data{
  int num; int idx;  
};
queue<Data> q;
int solution(vector<int> priorities, int location) {
    int answer = 0;
    for(int i = 0; i < priorities.size(); i++) q.push({priorities[i], i});
    
    sort(priorities.begin(), priorities.end());

    while(true){
        Data data = q.front(); q.pop();

        if(data.num >= priorities.back()){
            answer++;
            if(data.idx == location) break;
            priorities.pop_back();
        }
        else q.push(data);
    }
    return answer;
}