#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, temp, min, max;

    cin >> num;

    for(int i = 0; i < num; i++){
        cin >> temp;
        if(i == 0){
            min = temp;
            max = temp;
        }
        else{
            if(temp < min)
                min = temp;
            else if(temp > max)
                max = temp;
        }
    }
    cout << min << " " << max;
}