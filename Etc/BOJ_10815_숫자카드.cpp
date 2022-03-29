#include <iostream>
#include <algorithm>
using namespace std;
const int SIZE = 500000;
int N, M;
int card[SIZE];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    int input;
    for(int i = 0; i < N; i++){
        cin >> card[i];
    }
    sort(card, card + SIZE);
    cin >> M;
    for(int i = 0; i < M; i++){ 
        cin >> input;
        if(binary_search(card, card + SIZE, input))
            cout << '1' << ' ';
        else
            cout << '0' << ' ';
    }
}