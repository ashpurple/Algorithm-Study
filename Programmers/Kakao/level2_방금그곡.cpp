#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;
struct Music{
    int idx;
    int length;
    string name;
    bool operator<(const Music m) const{
        if(length == m.length) return idx < m.idx;
        return length > m.length;
    }
};

vector<Music> v;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
    return answer;
}

string convert(string str){
    string result = "";
    for(int i = 0 ; i < str.length(); i++){
        if(str[i] == '#') continue;
        else if(i + 1 == str.length()) result += str[i];
        else if(str[i + 1] == '#'){
            result += tolower(str[i]);
        }
        else result += str[i];
    }
    return result;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "";
    string my = convert(m);
    for(int i = 0; i < musicinfos.size(); i++){
        string musicinfo = musicinfos[i];
        vector<string> music = split(musicinfo, ',');
        // length
        int start = stoi(music[0].substr(0, 2)) * 60 + stoi(music[0].substr(3, 2));
        int end = stoi(music[1].substr(0, 2)) * 60 + stoi(music[1].substr(3, 2));
        int playtime = end - start;
        // name
        string name = music[2];
        // melody
        string melody = "";
        string comp = convert(music[3]);
        int musictime = comp.length();
        for(int i = 0; i < playtime; i++){
            int idx = i % musictime;
            melody += comp[idx];
            if(comp[(idx + 1) % musictime] == '#'){
                melody += '#';
                i++;
                playtime++;
            }
        }
        // match
        if(melody.find(my) != string::npos) v.push_back({i, playtime, name});
    }
    if(v.empty()) answer = "(None)";
    else{
        sort(v.begin(), v.end());
        answer = v[0].name;
    }
    
    return answer;
}