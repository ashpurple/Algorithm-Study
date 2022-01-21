#include <iostream>
#include <string>
#include <stack>
using namespace std;

string input;
string result = "";
stack<char> op;
char priority[] = {'*','/','+','-','(',')'};

bool isOper(char oper){
    for(int i = 0; i < 6; i++){
        if(oper == priority[i])
            return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> input;
    for(int i = 0; i < input.size(); i++){
        if(!isOper(input[i])){ // operand
            result += input[i];
            continue;
        } 
        else{ // operator
            if(input[i] == '('){
                op.push('(');
                continue;
            }
            else if(input[i] == ')'){
                while(op.top()!='('){
                    result += op.top();
                    op.pop();
                }
                op.pop();
                continue;
            }
            else if(input[i] == '*' || input[i] == '/'){
                while(!op.empty() && (op.top() == '*' || op.top() == '/')){
                    result += op.top();
                    op.pop();
                }
            }
            else{
                while(!op.empty() && (op.top() != '(')){
                    result += op.top();
                    op.pop();
                }
            }
            op.push(input[i]);
        }
    }

   while(!op.empty()){
       result += op.top();
       op.pop();
    }
    cout << result << '\n';
}