#include <iostream>
#include <string>
#include <stack>
using namespace std;
string input;
bool check(){
    stack <char> balance;
    for(int i = 0; i < input.length(); i++){
        if(input[i] == '(' || input[i] == '[') balance.push(input[i]);
        else if(input[i] == ')' || input[i] == ']'){
            if(balance.empty()) return false;
            if(balance.top() == '(' && input[i] == ']') return false;
            if(balance.top() == '[' && input[i] == ')') return false;
            balance.pop();
        }
    }
    if(!balance.empty()) return false;
    else return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(true){
        getline(cin, input);
        if(input == ".") break;
        if(check()) cout << "yes" << '\n';
        else cout << "no" << '\n';
    }
}