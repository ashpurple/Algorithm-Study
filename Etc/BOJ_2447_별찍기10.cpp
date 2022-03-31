#include <iostream>
#include <map>
using namespace std;
int N;

void divide(int cnt, int r, int c){
    if((r / cnt) % 3 == 1 && (c / cnt) % 3 == 1)
        cout << ' ';
    else if(cnt == 1)
        cout << '*';
    else
        divide(cnt / 3, r, c);
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j ++){
            divide(N, i, j);
        }
        cout << '\n';
    }

}