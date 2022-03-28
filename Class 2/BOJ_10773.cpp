#include <iostream>
#include <stack>
using namespace std;

int N;
stack<int> STACK;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int num;
    for(int i = 0; i < N; i++){
        cin >> num;
        if(num == 0) STACK.pop();
        else STACK.push(num);
    }

    int res = 0;
    while(!STACK.empty()){
        res += STACK.top();
        STACK.pop();
    }
    cout << res;
}