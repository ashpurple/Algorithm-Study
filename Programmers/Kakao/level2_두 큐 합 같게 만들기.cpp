#include <string>
#include <vector>
using namespace std;
long long sum1 = 0;
long long sum2 = 0;
long long sum = 0;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -1;
    
    for(int i = 0; i < queue1.size(); i++){
        sum1 += queue1[i];
        sum2 += queue2[i];
    }
    sum = sum1 + sum2;
    if(sum & 1 == 1) return answer;
    
    int left = 0;
    int right = 0;
    int value;
    int cnt = 0;
    int size = queue1.size();
    
    while(true){
        if(sum1 == sum2) return cnt;
        if(right > size * 2 || left > size * 2) break;
        else if(sum1 < sum2){
            if(right < size) value = queue2[right];
            else value = queue1[right - size];
            sum2 -= value;
            sum1 += value;
            right++;
            cnt++;
        }
        else{
            if(left < size) value = queue1[left];
            else value = queue2[left - size];
            sum1 -= value;
            sum2 += value;
            left++;
            cnt++;
        }
    }
    
    
    return answer;
}