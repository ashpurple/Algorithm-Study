#include <string>
#include <map>
using namespace std;
map <string, int> m1;
map <string, int> m2;

char convert(char ch){
    if('a' <= ch && ch <= 'z') return ch;
    if('A' <= ch && ch <= 'Z') return tolower(ch);
    else return '0';
}

int solution(string str1, string str2) {
    int answer = 0;
    
    for(int i = 0; i < str1.length() - 1; i++){
        char ch1 = convert(str1[i]);
        char ch2 = convert(str1[i + 1]);
        if(ch1 == '0' || ch2 == '0') continue;
        string str = "";
        str += ch1;
        str += ch2;
        m1[str]++;
    }
    for(int i = 0; i < str2.length() - 1; i++){
        char ch1 = convert(str2[i]);
        char ch2 = convert(str2[i + 1]);
        if(ch1 == '0' || ch2 == '0') continue;
        string str = "";
        str += ch1;
        str += ch2;
        m2[str]++;
    }
    double Inter = 0;
    double Union = 0;
    
    for(auto iter = m1.begin(); iter != m1.end(); iter++){
        string str = iter->first;
        if(m2.find(str) != m2.end()){
            Inter += min(m1[str], m2[str]);
            Union += max(m1[str], m2[str]);
            m1[str] = 0;
            m2[str] = 0;
        } 
        else{
            Union += m1[str];
        }
    }
    for(auto iter = m2.begin(); iter != m2.end(); iter++){
        string str = iter->first;
        Union += m2[str];
    }
    answer = (Inter / Union) * 65536;
    if(Union == 0) answer = 65536;
    
    return answer;
}