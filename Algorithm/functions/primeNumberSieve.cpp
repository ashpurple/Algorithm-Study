#include <iostream>
using namespace std;

int prime[1000];     
bool check[1001];      
int theNumOfPrimes;
int N;

void primeNumberSieve(){
    for (int i = 2; i <= N; ++i){
            if (!check[i]){
                prime[theNumOfPrimes] = i;
                theNumOfPrimes++;
            }
    
            for (int j = i * i; j <= N; j += i){
                // i * i Integer 범위 초과 조심
                if (!check[j]) check[j] = true;
            }
        }
}
