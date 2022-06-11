#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    cin >> T;

    for(int t = 0; t < T; t++){
        int y, m, d;
        cin >> y >> m;
        m--;

        if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
            d = 31;
        else if(m == 2)
            if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0){
                d = 29;
            }
            else d = 28;
        else
            d = 30;
        
        if(m == 0){
            d = 31;
            m = 12;
            y--;
        }
        cout << y << ' ' << m  << ' ' << d << '\n';

    }
}