#include <string>
#include <vector>
using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    vector<int> start, end;
    
    for(int i = 0; i < lines.size(); i++){
        int h, m, s, process;
    
        h = stoi(lines[i].substr(11, 2)) * 3600 * 1000;
        m = stoi(lines[i].substr(14, 2)) * 60 * 1000;
        s = stoi(lines[i].substr(17, 2)) * 1000;
        s += stoi(lines[i].substr(20, 3));
        
        process = stof(lines[i].substr(24, 5)) * 1000;
        start.push_back(h + m + s - process + 1);
        end.push_back(h + m + s);
    }
    int len = lines.size();
    for(int i = 0; i < len; i++){
        int end_time = end[i] + 1000;
        int count = 1;
        
        for(int j = i + 1; j < len; j++){
            if(start[j] < end_time) count++;
        }
        answer = max(answer, count);
    }
    return answer;
}