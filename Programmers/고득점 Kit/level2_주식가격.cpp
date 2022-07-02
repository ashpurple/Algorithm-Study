#include <string>
#include <vector>
#include <queue>
using namespace std;
struct Data{
    int time; int price;
    bool operator<(const Data d)const{
        return price < d.price;
    }
};
priority_queue<Data> pq;
int arr[100000];

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for(int i = 0; i < prices.size(); i++){
        pq.push({i, prices[i]});
        Data data;
        while(prices[i] < pq.top().price){
            data = pq.top();
            arr[data.time] = i - data.time;
            pq.pop();
        }
        if(i == prices.size() - 1){
            while(!pq.empty()){
                data = pq.top();
                arr[data.time] = i - data.time;
                pq.pop();
            }
        }
    }
    for(int i = 0; i < prices.size(); i++){
        answer.push_back(arr[i]);
    }
    
    return answer;
}