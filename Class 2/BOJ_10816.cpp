#include <iostream>
#include <string.h>

using namespace std;
int stack[10000], top = -1;

void push(int x){
    stack[++top] = x;
}
bool empty(){
    if(top < 0)
        return true;
    else
        return false;
}
void pop(){
    if(empty())
        cout << "-1" << '\n';
    else{
        cout << stack[top] << '\n';
        stack[top--] = 0;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    int num ,m;
    cin >> num;

    for(int i = 0; i < num; i++){
        string command;
        cin >> command; 

        if(command == "push"){
            int x;
            cin >> x;
            push(x);
        }
        else if (command == "top"){
            if (empty() == 1)
                cout << "-1"<< '\n';
            else 
                cout << stack[top] << '\n';
        }
        else if (command == "pop"){
            pop();
        }
        else if (command == "empty") {
            cout << empty() << "\n";
        }
        else { // size
            cout << top + 1 << "\n";
        }
    }

}
