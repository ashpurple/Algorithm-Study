#include <vector>
#include <queue>
using namespace std;
queue<int> q;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    for(int i = 0; i < progresses.size(); i++){
        int day = (100 - progresses[i]) / speeds[i];
        if((100 - progresses[i]) % speeds[i] != 0) day++;
        q.push(day);
    }

    int cnt = 1;
    int prev = q.front(); q.pop();
    while(!q.empty()){
        int day = q.front(); q.pop();
        if(day <= prev) cnt++; 
        else{
            answer.push_back(cnt);
            prev = day;
            cnt = 1;
        }
        if(q.empty()) answer.push_back(cnt);
    }
   
    return answer;
}