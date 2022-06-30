#include <string>
#include <vector>
#include <map>
using namespace std;

map <string, int> m;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    for(vector<string> clothe : clothes){
        string name = clothe[0];
        string category = clothe[1];
        m[category]++;
    }
    int combi = 1;
    for(auto iter : m){
        combi *= (iter.second + 1);
    }
    answer = combi - 1;
    
    return answer;
}