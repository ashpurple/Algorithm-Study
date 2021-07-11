#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        string number;
        string result = "yes";

        cin >> number;
        if(number[0] == '0')
            break;
            
        int size = number.size();

        for(int i = 0; i < size / 2; i++){
            if(number[i] != number[size - i - 1]){
                result = "no";
                break;
            }
        }
        cout << result << '\n';
    }
}