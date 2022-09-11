#include <string>
#include <algorithm>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int score[3];
    int idx = 0;
    for(int i = 0; i < dartResult.length(); i++){
        char ch = dartResult[i];
        if(ch == '*' || ch == '#'){
            int mul = 1;
            if(ch == '*'){
                mul *= 2;
                if(idx >= 2) score[idx - 2] *= mul;
            }
            else mul *= -1;
            score[idx - 1] *= mul;
        }
        else if(ch == 'S' || ch == 'D' || ch == 'T'){
            if(ch == 'D') score[idx] *= score[idx];
            else if(ch == 'T') score[idx] = score[idx] * score[idx] * score[idx];
            idx++;
        }
        else{ // number
            int num = ch - '0';
            if(i + 1 < dartResult.length()){
                if(dartResult[i + 1] == '0'){
                    num = 10;
                    i++;
                }
            }
            score[idx] = num;
        }
    }
    for(int i = 0; i < 3; i++) answer += score[i];
    
    return answer;
}