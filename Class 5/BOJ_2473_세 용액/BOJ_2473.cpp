#include <iostream>
#include <algorithm>
using namespace std;

int N;
long long minSum = 3000000001;
long long result[3];
long long solution[5000];

void twoPointer(int l, int r, int idx){
    if(l == r) return;

    long long sum = solution[l] + solution[r] + solution[idx];
    if(abs(sum) < minSum) {
        minSum = abs(sum);
        result[0] = solution[idx];
        result[1] = solution[l];
        result[2] = solution[r];
        
    }
    if(0 <= sum) twoPointer(l, r - 1, idx);
    if(sum < 0) twoPointer(l + 1, r, idx);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++){
        cin >> solution[i];
    }

    sort(solution, solution + N);

    for(int i = 0; i < N - 2; i++) twoPointer(i + 1, N - 1, i);
    
    for(int i = 0; i < 3; i++) cout << result[i] << " ";
}