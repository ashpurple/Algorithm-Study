#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> names;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    for(string str: participant){
        names[str] += 1;
    }
    for(string str: completion){
        names[str] -= 1;
    }
    for(auto iter : names){
        if(iter.second > 0) answer = iter.first;
    }

    return answer;
}