#include <vector>
#include <map>
using namespace std;
map <int, int> m;

int solution(vector<int> nums){
    int answer = 0;
    int size = nums.size() / 2;
    
    for(int num : nums){
        m[num] = 1;
    }
    int cnt = m.size();
    if(cnt < size) answer = cnt;
    else answer = size;
    
    return answer;
}