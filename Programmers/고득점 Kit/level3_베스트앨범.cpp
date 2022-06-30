#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
struct Song{
    int num; string genre; int plays;
    bool operator<(const Song &s) const {
        if(plays == s.plays) return num < s.num;
		return plays > s.plays;
	}
};
map<string, int> genreMap;
vector<Song> songs;

string getTopGenre(){
    int maximum = 0;
    string top;
    for(auto iter : genreMap){
        if(maximum < iter.second){
            top = iter.first;
            maximum = iter.second;
        }
    }
    return top;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    for(int i = 0; i < plays.size(); i++){
        genreMap[genres[i]] += plays[i];
        songs.push_back({i, genres[i], plays[i]});
    }
    sort(songs.begin(),songs.end());
    
    // get TopGenre
    vector<string> topGenre;
    while(genreMap.size() != 0){
        string name = getTopGenre();
        topGenre.push_back(name);
        genreMap.erase(name);
    }
    for(int i = 0; i < topGenre.size(); i++){
        int cnt = 0;
        for(Song song : songs){
            if(song.genre == topGenre[i]){
                answer.push_back(song.num);
                cnt++;
            }
            if(cnt == 2) break;
        }
    }
    
    return answer;
}