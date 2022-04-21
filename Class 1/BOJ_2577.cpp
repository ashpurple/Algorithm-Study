#include <iostream>
using namespace std;
int cnt[10];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;
    int num = a * b * c;
    
    while(num > 0){
        int i = num % 10;
        cnt[i]++;
        num /= 10;
    }
    for(int i = 0; i < 10; i++) cout << cnt[i] << "\n";


}