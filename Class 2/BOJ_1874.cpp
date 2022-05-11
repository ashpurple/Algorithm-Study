#include <iostream>
#include <vector>
using namespace std;
int N;
int num[100000];
vector <int> STACK;
vector <char> ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++) cin >> num[i];
    
    int j = 0;
    for(int i = 1; i <= N; i++){
        STACK.push_back(i);
        ans.push_back('+');
        while(!STACK.empty() && STACK.back() == num[j]){
            STACK.pop_back();
            ans.push_back('-');
            j++;
        }
    }

    if(!STACK.empty()) cout << "NO";
    else{
        for(char ch : ans) cout << ch << '\n';
    }
}