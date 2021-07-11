#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int index = 1, max, temp;

    for(int i = 0; i < 9; i++){
        cin >> temp;
        if(i == 0){
            max = temp;
        }
        else{
            if(temp > max){
                max = temp;
                index = i + 1;
            }
        }
    }
    cout << max << "\n" << index;
}