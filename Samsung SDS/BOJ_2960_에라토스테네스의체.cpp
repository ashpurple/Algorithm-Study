#include <iostream>
using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int prime[1000];          
    int theNumOfPrimes = 0;
    bool check[1001] = {false}; 
    int N, K;
    int cnt = 0;
    cin >> N >> K;
    
    for (int i = 2; i <= N; ++i){
        if (check[i] == false){
            prime[theNumOfPrimes] = i;
            theNumOfPrimes++;
            cnt++;
            if(cnt == K){
                cout << i;
                break;
            }
        }
 
        for (int j = i * i; j <= N; j += i){
            if (check[j] == false){
                check[j] = true;
                cnt++;
                if(cnt == K){
                    cout << j;
                    break;
                }
            }
        }
    }
 
    return 0;
    
    
}