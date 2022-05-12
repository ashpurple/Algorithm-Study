#include <iostream>
using namespace std;
long long N, M;

int prime[1000000];     
bool check[1000001];      
int theNumOfPrimes;

void primeNumberSieve(){
    for (long long i = 2; i <= N; ++i){
            if (!check[i]){
                prime[theNumOfPrimes] = i;
                theNumOfPrimes++;
            }
    
            for (long long j = i * i; j <= N; j += i){
                if (!check[j]) check[j] = true;
            }
        }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N;
    primeNumberSieve();
    for(int i = 0; i < theNumOfPrimes; i++){
        if(prime[i] < M) continue;
        cout << prime[i] << '\n';
    }
}