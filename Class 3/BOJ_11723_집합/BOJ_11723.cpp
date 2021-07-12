#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int num, bits = 0;
    cin >> num;

    for(int i = 0; i < num; i++){
        string cmd;
        int val;
        cin >> cmd;

        if(cmd == "add"){
            cin >> val;
            bits |= (1 << val - 1);
        }
        else if(cmd == "remove"){
            cin >> val;
            bits &= ~(1 << val - 1);
        }
        else if(cmd == "check"){
            cin >> val;
            if(bits & (1 << val - 1))
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if(cmd == "toggle"){
            cin >> val;
            bits ^= (1 << val - 1);
        }
        else if(cmd == "all"){
            bits = (1 << 20) - 1;
        }
        else if(cmd == "empty"){
            bits = 0;
        }

    }

}