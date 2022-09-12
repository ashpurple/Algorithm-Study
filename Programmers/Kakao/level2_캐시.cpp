#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;
vector <string> cache;
int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    for(auto city : cities){
        for(int i = 0; i < city.length(); i++){
            city[i] = tolower(city[i]);
        }
        bool flag = true; // no found
        for(auto iter = cache.begin(); iter != cache.end(); iter++){
            if(*iter == city){
                cache.erase(iter);
                cache.push_back(city);
                flag = false; // hit
                answer += 1;
                break;
            }
        }
        if(flag){
            if(!cache.empty() && cache.size() >= cacheSize) cache.erase(cache.begin());
            if(cache.size() < cacheSize) cache.push_back(city);
            answer += 5;
        }
    }
    return answer;
}