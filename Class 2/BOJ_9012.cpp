#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, cnt = 0;
    bool flag;
    string ps;
    
    cin >> num;

    for(int i = 0; i < num; i++){
        cin >> ps;
        cnt = 0;
        for(int j = 0; j < ps.size(); j++){

            if(ps[j] == '(')
                cnt++;
            else if(cnt > 0)
                cnt--;
            else{
                cnt --;
                break;
            }
        }
        if(cnt == 0)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';

    }
  
}