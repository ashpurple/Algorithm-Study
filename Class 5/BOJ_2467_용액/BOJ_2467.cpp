#include <iostream>
using namespace std;

int N, sum;
int minSum = 2000000000;
int result[2];
int solution[100000];

void twoPointer(int l, int r){
    if(l == r) return;

    sum = abs(solution[l] + solution[r]);
    if(sum < minSum) {
        minSum = sum;
        result[0] = solution[l];
        result[1] = solution[r];
    }
    if(abs(solution[l]) < solution[r]) twoPointer(l, r - 1);
    if(abs(solution[l]) > solution[r]) twoPointer(l + 1, r);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> solution[i];
    }
    twoPointer(0, N - 1);
    cout << result[0] << ' ' << result[1];
}