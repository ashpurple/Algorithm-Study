#include <iostream>
#include <algorithm>
using namespace std;
int N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    int cnt = 0;
    int i = 666;
    while(true){
        int num = i;
        while(num){
            if(num % 1000 == 666){
                cnt++;
                break;
            }
            num /= 10;
        }
        if(cnt == N){
            cout << i;
            break;
        }
        i++;
    }
}