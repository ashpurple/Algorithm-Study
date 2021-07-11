#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(true){
        int x[3];
        string result = "wrong";
        
        cin >> x[0] >> x[1] >> x[2];

        if(x[0] == 0 && x[1] == 0 && x[2] == 0)
            break;

        for(int i = 0; i < 3; i++){
            int temp = x[0];
            x[0] = x[2];
            x[2] = x[1];
            x[1] = temp;

            if(x[0] * x[0] + x[1] * x[1] == x[2] * x[2])
                result = "right";
        }
        cout << result << "\n";
    }
}