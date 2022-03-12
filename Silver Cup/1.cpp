#include <iostream>
using namespace std;

int T;
int num[3];
int cnt;
int minimum = 1987654321;
int minIdx, maxIdx;
int maximum;

void simulate2(){
    minimum = 1987654321;
    for(int i = 0; i < 3; i ++){
        if(num[i] < minimum){
            minIdx = i;
            minimum = num[i];
        }
    }
    for(int i = 0; i < 3; i ++){
        if(i == minIdx){
            num[i]++;
            continue;
        }
        num[i]--;
        if(num[i] < 0) return;
    }
    cnt++;
    simulate2();
}

void simulate1(){
    while(true){
        maximum = max(num[0], max(num[1], num[2]));
        for(int i = 0; i < 3; i ++){
            if(num[i] == maximum){
                if(num[i] < 2){
                    simulate2();
                    return;
                }
                num[i] = num[i] & 1;
                break;
            }
        }
        // for(int i = 0; i < 3; i++) cout << num[i] << ' ';
        // cout << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    for(int i = 0; i < T; i++){
        cnt = 0;
        for(int i = 0; i < 3; i++) cin >> num[i];
        simulate1();
        if((cnt & 1) == 1) cout << "B" << '\n';
        else if((cnt & 1) == 0) cout << "R" << '\n';
    }
}