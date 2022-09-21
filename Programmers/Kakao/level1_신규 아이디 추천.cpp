#include <string>
#include <vector>
#include <algorithm>
#include <ctype.h>
using namespace std;

string solution(string new_id) {
    string answer = "";
    
    for(int i = 0; i < new_id.length(); i++){ // 1
        if('A' <= new_id[i] && new_id[i] <= 'Z')
               new_id[i] -= ('A' - 'a');
    }
    
    for(char ch : new_id){ // 2
        if(isalpha(ch) || ch == '-' || ch == '_' || ch == '.') answer += ch;
        else if('0' <= ch && ch <= '9') answer += ch;
    }
    
    int cnt = 0;
    for(int i = 0; i < answer.length(); i++){ // 3
        if(answer[i] == '.') cnt++;
        else cnt = 0;
        if(2 <= cnt) answer[i] = '!';
    }
    answer.erase(remove(answer.begin(), answer.end(), '!'), answer.end());
    
    if(answer.length() > 0 && answer[0] == '.') answer.erase(0, 1);
    if(answer.length() > 0 && answer[answer.length() - 1] == '.') answer.erase(answer.length() - 1);
    
    if(answer.length() == 0) answer += 'a';
    if(answer.length() >= 16) answer.erase(15);
    if(answer[answer.length() - 1] == '.') answer.erase(answer.length() - 1);
    
    while(answer.length() < 3){
        answer += answer[answer.length() - 1];
    }

    return answer;
}