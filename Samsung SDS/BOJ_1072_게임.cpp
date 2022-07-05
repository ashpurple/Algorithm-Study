#include <iostream>
using namespace std;
const int MAX = 1000000000;
long long X, Y;
int ans;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> X >> Y;
    int Z = (Y * 100) / X;
    int low = 0;
    int high = MAX;
    while(low <= high){
        int mid = low + (high - low) / 2;
        long long nZ = (100 * (Y + mid)) / (X + mid);
        if(Z < nZ){
            high = mid - 1;
            ans = mid;
        }
        else low = mid + 1;
    }
    if(Z >= 99) cout << -1;
    else cout << ans;
}
