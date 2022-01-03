#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    while(true){
        vector <pair<string, int>> cmdList;
        while(true){
            string cmd;
            int number = 0;
            cin >> cmd; 

            if(cmd == "QUIT")
                return 0;
            if(cmd == "END")
                break;
            if(cmd == "NUM")
                cin >> number;
            cmdList.push_back({cmd, number});
        }

        int num;
        cin >> num;
        for(int i = 0; i < num; i++){
            stack<long> STACK;
            bool flag = true;

            long input;
            cin >> input;
            STACK.push(input);
            for(int j = 0; j < cmdList.size(); j++){
                pair<string, int> cmd = cmdList[j];
                if(cmd.first == "NUM"){
                    int number = cmd.second;
                    STACK.push(number);
                }
                
                else if(cmd.first == "POP"){
                    if(!STACK.empty()){
                        STACK.pop();
                    } else{
                        flag = false;
                    }
                }
            
                else if(cmd.first == "INV"){
                    if(!STACK.empty()){
                        long top = STACK.top();
                        STACK.pop();
                        STACK.push(top * -1);
                    } else{
                        flag = false;
                    }
                }
            
                else if(cmd.first == "DUP"){
                    if(!STACK.empty()){
                        long top = STACK.top();
                        STACK.push(top);
                    } else{
                        flag = false;
                    }
                }
                
                else if(cmd.first == "SWP"){
                    if(STACK.size() >= 2){
                        long first = STACK.top();
                        STACK.pop();
                        long second = STACK.top();
                        STACK.pop();
                        STACK.push(first);
                        STACK.push(second);
                    } else{
                        flag = false;
                    }
                }
            
                else if(cmd.first == "ADD"){
                    if(STACK.size() >= 2){
                        long first = STACK.top();
                        STACK.pop();
                        long second = STACK.top();
                        STACK.pop();
                        long sum = first + second;
                        if(abs(sum) > 1000000000){
                            flag = false;
                            break;
                        }
                        STACK.push(sum);
                    } else{
                        flag = false;
                    }
                }
            
                else if(cmd.first == "SUB"){
                    if(STACK.size() >= 2){
                        long first = STACK.top();
                        STACK.pop();
                        long second = STACK.top();
                        STACK.pop();
                        long sub = second - first;
                        if(abs(sub) > 1000000000){
                            flag = false;
                            break;
                        }
                        STACK.push(sub);
                    } else{
                        flag = false;
                    }
                }
            
                else if(cmd.first == "MUL"){
                    if(STACK.size() >= 2){
                        long first = STACK.top();
                        STACK.pop();
                        long second = STACK.top();
                        STACK.pop();
                        long mul = first * second;
                        if(abs(mul) > 1000000000){
                            flag = false;
                            break;
                        }
                        STACK.push(mul);
                    } else{
                        flag = false;
                    }
                }
            
                else if(cmd.first == "DIV"){
                    if(STACK.size() >= 2){
                        long first = STACK.top();
                        STACK.pop();
                        long second = STACK.top();
                        STACK.pop();
                        if(first == 0){
                            flag = false;
                            break;
                        }
                        long div = abs(second) / abs(first);
                        
                        if(first * second < 0)
                            div *= -1;
                        if(abs(div) > 1000000000){
                            flag = false;
                            break;
                        }
                        STACK.push(div);
                    } else{
                        flag = false;
                    }
                }
                    
                else if(cmd.first == "MOD"){
                    if(STACK.size() >= 2){
                        long first = STACK.top();
                        STACK.pop();
                        long second = STACK.top();
                        STACK.pop();
                        if(first == 0){
                            flag = false;
                            break;
                        }
                        long mod = abs(second) % abs(first);
                        if(second < 0)
                            mod *= -1;
                        if(abs(mod) > 1000000000){
                            flag = false;
                            break;
                        }
                        STACK.push(mod);
                    } else{
                        flag = false;
                    }
                }
            }
            if(STACK.size() != 1 || !flag){
                    cout << "ERROR" << "\n";
            }
            else{
                cout << STACK.top() << "\n";
            }
        }
        cout << "\n";
    }
}
