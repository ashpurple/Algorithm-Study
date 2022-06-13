#include <iostream>
using namespace std;
int N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string str;
    cin >> N >> str;
    for(int i = 0; i < N; i++) cout << str;
}