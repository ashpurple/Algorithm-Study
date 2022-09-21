#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;
map <string,vector<int>> m;

void makeMap(string *s, int score){
    for(int i = 0; i < 16; i++){
        string str= "";
        int num = i;
        for(int j = 3; j >= 0; j--){
            if(num <= 0 || num %2 == 0) str = "-" + str;
            else str = s[j] + str;
            num /= 2;
        }
        m[str].push_back(score);
    }
}
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    string category[4];
    string str = "";
    
    for(int i = 0; i < info.size(); i++){
        istringstream stt(info[i]);
        stt >> category[0] >> category[1] >> category[2] >> category[3] >> str;
        makeMap(category, (int)stoi(str));
    }
    
    for(auto iter = m.begin(); iter!=m.end(); iter++){
        sort(iter->second.begin(), iter->second.end());
    }
    
    for(int i = 0; i < query.size(); i++){
        istringstream stt(query[i]);
        stt >> category[0] >> str >> category[1] >> str >> category[2] >> str >> category[3] >> str;
        int score = (int)stoi(str);
        
        vector <int> v = m[category[0]+category[1]+category[2]+category[3]];
        if(v.size() != 0){
            int idx = lower_bound(v.begin(), v.end(), score) - v.begin();
            answer.push_back(v.size() - idx);
        }
        else answer.push_back(0);
    }
    return answer;
}