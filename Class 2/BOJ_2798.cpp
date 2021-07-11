#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M;
    int cards[100];
    cin >> N >> M;

    for(int t = 0; t < N; t++)
        cin >> cards[t];

    int max = 0;

    for(int i = 0; i < N - 2; i++){
        int first = cards[i];
        for(int j = i + 1; j < N - 1; j++){
            int second = cards[j];
            for(int k = j + 1; k < N; k++){
                int third = cards[k];
                int sum = first + second + third;
                if(sum <= M && sum > max)
                    max = sum;
            }
        }
    }
    cout << max;
}