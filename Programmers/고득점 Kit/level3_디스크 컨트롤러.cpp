#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
struct Task{
    int start, len;
    bool operator<(const Task task) const{
        return len > task.len;
    }
};
priority_queue<Task> pq;
int times;
int num;

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    sort(jobs.begin(), jobs.end());
    while(num < jobs.size() || !pq.empty()){
        if(num < jobs.size() && jobs[num][0] <= times){
            auto job = jobs[num++];
            pq.push({job[0], job[1]});
            continue;
        }
        if(!pq.empty()){
            Task task = pq.top(); pq.pop();
            times += task.len;
            answer += times - task.start;
        }
        else times = jobs[num][0];
    }
    answer /= jobs.size();
    return answer;
}