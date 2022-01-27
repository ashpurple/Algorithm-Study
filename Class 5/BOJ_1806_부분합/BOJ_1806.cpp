#include <iostream>
#define MAX 987654321
using namespace std;

int N, S;
int arr[100001];
int len = MAX;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int start = 1;
    int end = 1;

    cin >> N >> S;
    for(int i = 1; i <= N; i++) 
        cin >> arr[i];

    int total = arr[1];

    while(start <= end && end <= N){
        if(total >= S) len = min(len, (end - start + 1));
        if(total < S) {
            end++; 
            total += arr[end];
        } else {
            total -= arr[start];
            start++;
        }
    }

    if(len == MAX) cout << '0';
    else cout << len;
}