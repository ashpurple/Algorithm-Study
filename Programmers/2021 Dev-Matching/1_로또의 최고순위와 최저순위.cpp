#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int cnt = 0;
    int zero_cnt = 0;

    for(int i : lottos){
        if(i == 0){
            zero_cnt++;
            continue;
        }
        for(int j : win_nums){
            if(i == j){
                cnt++; break;
            }
        }
    }
    
    int rowRank = 7 - cnt;
    if(rowRank >= 7) rowRank = 6;
    int topRank = 7 - (cnt + zero_cnt);
    if(topRank >= 7) topRank = 6;
    
    answer.push_back(topRank);
    answer.push_back(rowRank);
    return answer;
}