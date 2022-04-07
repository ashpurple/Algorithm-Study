#include <iostream>
using namespace std;

int stringToNum(string str){
    int num = 0;
    int mul = 1;
    for(int i = str.length() - 1; 0 <= i; i--){
        int digit = str[i] - '0';
        num += digit * mul;
        mul *= 10;
    }
    return num;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    cin >> input;

    string temp = "";
    int res = 0;
    int flag = false;
    
    for(int i = 0; i <= input.length(); i++){
        char c = input[i];
        if(c == '+' || c == '-' || c == '\0'){
            if(flag) res -= stringToNum(temp);
            else res += stringToNum(temp);
            if(c == '-') flag = true;
            temp = "";
        }
        else temp += c;
    }

    cout << res;
}