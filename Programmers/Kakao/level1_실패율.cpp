#include <string>
#include <vector>
#include <algorithm>

using namespace std;
struct Info{
    int level;
    double fail;
    bool operator<(const Info d) const {
        if(fail == d.fail) return level < d.level;
        return fail > d.fail;
    }
};
int cnt[501];

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<Info> v;
    int num = stages.size();
    
    for(int stage : stages){
        cnt[stage]++;
    }
    
    for(int i = 1; i <= N; i++){
        if(num == 0){
            v.push_back({i, 0});
            continue;
        }
        double fail = (double) cnt[i] / num;
        num -= cnt[i];
        v.push_back({i, fail});
    }
    
    sort(v.begin(), v.end());
    for(Info info : v){
        answer.push_back(info.level);
    }
    
    return answer;
}