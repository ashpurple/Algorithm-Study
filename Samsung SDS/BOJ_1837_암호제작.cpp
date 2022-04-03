#include <iostream>
using namespace std;
  
bool check[1000001];      
string P;
int K;

void primeNumberSieve(){
    for (int i = 2; i <= K; ++i){
        if (check[i]) continue;
        for (int j = i * 2; j <= K; j += i){
            if (!check[j])
                check[j] = true;
        }
    }
}

bool isBad(int num){
    long long res = 0;
    for (int i = 0; i < P.length(); i++)
        res = (res * 10 + (P[i] - '0')) % num;
    if(res == 0) return true;
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> P >> K;
    primeNumberSieve();

    bool flag = true;
    int prime;
    for(int i = 2; i < K; i++){
        if(check[i]) continue;
        if(isBad(i)){
            flag = false;
            prime = i;
            break;
        }
    }
    if(flag) cout << "GOOD";
    else cout << "BAD " <<  prime;
}