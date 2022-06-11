#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        string input[4];
        for(int j = 0; j < 4; j++){
            cin >> input[j];
        }
        sort(input, input + 4);
        
        bool flag = false;
        if(input[0] == input[2] || input[1] == input[3])
            flag = true;
        if(input[0] == input[1] && input[2] == input[3])
            flag = true;
        if(input[0][0] + 1 == input[1][0] && input[1][0] + 1 == input[2][0])
            if(input[0][1] == input[1][1] && input[1][1] == input[2][1])  
                flag = true;
        if(input[1][0] + 1 == input[2][0] && input[2][0] + 1 == input[3][0])
            if(input[1][1] == input[2][1] && input[2][1] == input[3][1])
                flag = true;
        if(input[0][0] + 1 == input[1][0] && input[1][0] + 1 == input[3][0])
            if(input[0][1] == input[1][1] && input[1][1] == input[3][1])
                flag = true;
        if(input[0][0] + 1 == input[2][0] && input[2][0] + 1 == input[3][0])
            if(input[0][1] == input[2][1] && input[2][1] == input[3][1])
                flag = true;

        if(flag) cout << ":)" << '\n';
        else cout << ":(" << '\n';
    }
}