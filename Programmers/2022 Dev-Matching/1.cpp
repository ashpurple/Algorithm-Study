#include <vector>
using namespace std;

int solution(vector<int> grade) {
    int answer = 0;
    int N = grade.size() - 1;
    int minimum = grade[N];
    for(int i = N - 1; 0 <= i; i--){
        minimum = min(minimum, grade[i]);
        if(grade[i] > minimum){
            answer += (grade[i] - minimum);
        }
    }
    return answer;
}