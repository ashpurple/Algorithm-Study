#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    float num[1000];
    float sum = 0;
    float maxNum = 0;
    for(int i = 0; i < N; i++){
        cin >> num[i];
        maxNum = max(maxNum, num[i]);
    }
    for(int i = 0; i < N; i++)
        sum = sum + (num[i] / maxNum * 100);
    cout << sum / N;
}