#include <iostream>
#include <algorithm>
using namespace std;

struct Data{
    int x, y;
    bool operator<(const Data d) const{
        if(y == d.y) return x < d.x;
        return y < d.y;
    }
};

int N;
Data arr[100000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int x, y;
    for(int i = 0; i < N; i++){
        cin >> x >> y;
        arr[i] = {x, y};
    }
    sort(arr, arr + N);
    for(int i = 0; i < N; i++)
        cout << arr[i].x << ' ' << arr[i].y << '\n';

}
