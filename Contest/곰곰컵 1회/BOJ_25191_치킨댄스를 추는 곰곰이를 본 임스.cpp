#include <iostream>
using namespace std;
int N;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B;
    cin >> N >> A >> B;

    A >>= 1;
    int drink = A + B;
    if(N > drink) cout << drink;
    else cout << N;
    
}