#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, R;
    string str;
    
    cin >> num;

    for(int i = 0; i < num; i++){
        cin >> R >> str;
        
        for(int j = 0; j < str.size(); j++){
            for(int k = 0; k < R; k++)
                cout << str[j];
        }
        cout << "\n";
    }
}