#include <iostream>
using namespace std;
int N;
int c_cnt;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    cin >> N;
    cin >> input;

    for(char ch : input){
        if(ch == 'C') c_cnt++;
    }
    int div = N - c_cnt + 1;
    if(div == 0) cout << c_cnt;
    if(c_cnt % div == 0) cout << c_cnt / div;
    else cout << (c_cnt / div) + 1;

}