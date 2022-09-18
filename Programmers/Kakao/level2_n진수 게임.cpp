#include <string>
#include <vector>
using namespace std;
string digit = "0123456789ABCDEF";

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    int dec = 0;
    int order = 0;
    while(true){
        int num = dec++;
        string str = "";
        if(num == 0) str = "0";
        while(num != 0){
            str = digit[num % n] + str;
            num /= n;
        }
        
        for(char ch : str){
            if((order % m) == (p - 1)) answer += ch;
            if(answer.length() == t) return answer;
            order++;
        }
    }
    
    return answer;
}