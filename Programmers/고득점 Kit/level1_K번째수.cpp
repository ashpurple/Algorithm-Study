#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(vector<int> command : commands){
        
        vector<int> list;
        for(int i = command[0] - 1; i < command[1]; i++){
            list.push_back(array[i]);
        }
        sort(list.begin(), list.end());
        answer.push_back(list[command[2] - 1]);
    }
    
    return answer;
}