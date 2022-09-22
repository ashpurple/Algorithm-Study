#include <string>
#include <vector>
using namespace std;
int mbti[4];

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    for(int i = 0; i < survey.size(); i++){
        char ch = survey[i][0];
        int score = choices[i] - 4;
        if(survey[i][0] > survey[i][1]) score *= -1;
        
        if(ch == 'R' || ch == 'T') mbti[0] += score;
        else if(ch == 'C' || ch == 'F') mbti[1] += score;
        else if(ch == 'J' || ch == 'M') mbti[2] += score;
        else if(ch == 'A' || ch == 'N') mbti[3] += score;
    }
    if(mbti[0] <= 0) answer += 'R';
    else answer += 'T';
    if(mbti[1] <= 0) answer += 'C';
    else answer += 'F';
    if(mbti[2] <= 0) answer += 'J';
    else answer += 'M';
    if(mbti[3] <= 0) answer += 'A';
    else answer += 'N';
    
    return answer;
}