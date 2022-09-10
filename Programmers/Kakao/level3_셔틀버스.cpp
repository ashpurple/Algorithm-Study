#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector <int> krew;
    
    for(auto str : timetable){
        krew.push_back(stoi(str.substr(0, 2)) * 60 + stoi(str.substr(3, 2)));
    }
    
    sort(krew.begin(), krew.end());
    
    vector <int> lastLine;
    int lastTime;
    int busTime = 9 * 60;
    int krewNum = krew.size();
    int idx = 0;
    for(int i = 0; i < n; i++){
       for(int j = 0; j < m; j++){
          if(idx >= krewNum) break; 
          if(krew[idx] <= busTime){
              if(i == n - 1) lastLine.push_back(krew[idx]);
              idx++;
          } else break;
       }
       
       if(i == n - 1){
           if(lastLine.size() < m) lastTime = busTime;
           else lastTime = lastLine[lastLine.size() - 1] - 1;
       }
       busTime += t; 
    }
    
    answer = to_string(lastTime / 60);
    if(lastTime / 60 < 10) answer = "0" + answer;
    answer += ":";
    if(lastTime % 60 < 10) answer += "0" + to_string(lastTime % 60);
    else answer += to_string(lastTime % 60);
    
    return answer;
}