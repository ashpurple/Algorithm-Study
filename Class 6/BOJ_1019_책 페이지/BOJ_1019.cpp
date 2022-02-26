#include<iostream>
using namespace std;

int N;
int cnt[10];
int digit = 1;

void count(int n){
    while(n > 0){
        cnt[n % 10] += digit;
        n /= 10;
    }
}

void solve(){
    int start = 1;
    int end = N;

    while(start <= end){
        
        while(start % 10 != 0 && start <= end) count(start++);

        if(end < start) return;

        while(end % 10 != 9 && start <= end) count(end--);
    
        start /= 10;
        end /= 10;
        int diff = end - start + 1;
        for(int i = 0; i < 10; i++) cnt[i] += diff * digit;
        digit *= 10;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    solve();
    for(int i = 0; i < 10; i++) cout << cnt[i] << ' ';
}