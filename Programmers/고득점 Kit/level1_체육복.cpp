#include <string>
#include <vector>
using namespace std;
int student[31];
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    for(int i = 1; i <= n; i++) student[i]++;
    for(int num : lost) student[num]--;
    for(int num : reserve) student[num]++;
    
    for(int i = 1; i <= n; i++){
        if(1 < i && student[i] > 1 && student[i - 1] == 0){
            student[i]--;
            student[i - 1]++;
        }
        else if(i < n && student[i] > 1 && student[i + 1] == 0){
            student[i]--;
            student[i + 1]++;
        }
    }
    for(int i = 1; i<= n; i++){
        if(student[i]) answer++;
    }
    
    return answer;
}