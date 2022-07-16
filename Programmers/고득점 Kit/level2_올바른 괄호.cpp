#include<string>
#include <iostream>
using namespace std;

bool solution(string s){
    bool answer = true;
    
    int cnt = 0;
    for(char ch : s){
        if(ch == '(') cnt++;
        else cnt--;
        if(cnt < 0){
            answer = false;
            break;
        }
    }
    if(cnt != 0) answer = false;
    return answer;
}