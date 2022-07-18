#include <string>
#include <vector>
using namespace std;
int cnt[3];
int cnt1, cnt2, cnt3;
int idx, idx2, idx3;
int rank[3];

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int ans1[5] = {1, 2, 3, 4, 5};
    int ans2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int ans3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for(int num : answers){
        if(ans1[idx++] == num) cnt[0]++;
        if(ans2[idx2++] == num) cnt[1]++;
        if(ans3[idx3++] == num) cnt[2]++;
        idx %= 5;
        idx2 %= 8;
        idx3 %= 10;
    }
    int high = max(max(cnt[0], cnt[1]), cnt[2]);
    for(int i = 0; i < 3; i++){
        if(high == cnt[i]) answer.push_back(i + 1);
    }
    
    return answer;
}