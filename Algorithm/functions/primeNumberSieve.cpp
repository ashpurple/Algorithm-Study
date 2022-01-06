#include <iostream>
using namespace std;

int prime[1000];     
bool check[1001] = {false};      
int theNumOfPrimes = 0;
int N;

void primeNumberSieve(){
    for (int i = 2; i <= N; ++i){
            if (check[i] == false){
                prime[theNumOfPrimes] = i;
                theNumOfPrimes++;
            }
    
            for (int j = i * i; j <= N; j += i){
                if (check[j] == false){
                    check[j] = true;
                }
            }
        }
}
