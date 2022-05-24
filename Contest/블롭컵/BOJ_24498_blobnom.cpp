#include <iostream>
#define MAX 1000000
using namespace std;

int N;
int num[MAX];
int ans;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> num[i];
    }
    int maxTemp = 0;
    int temp;
    for(int i = 1; i < N - 1; i++){
        temp = min(num[i - 1], num[i + 1]);
        maxTemp = max(maxTemp, temp + num[i]);
    }
    if(N == 1) cout << num[0];
    else if(N == 2) cout << max(num[0], num[1]);
    else{
        int end = max(num[0], num[N - 1]);
        maxTemp = max(end, maxTemp);
        cout << maxTemp;
    }
}