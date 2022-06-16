#include <iostream>
#include <vector>
using namespace std;
vector <long long> arr;
bool flag = true;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    long long sum = 0;
    for(int i = 0; i < N; i++){
        long long num;
        cin >> num;
        
        arr.push_back(num);
        sum += num;
    }

    for(int i = 0; i < N; i++){
        if(sum < 2 * arr[i]) flag = false;
    }
    
    if(N == 1 && arr[0] == 1) flag = true;

    if(flag) cout << "Happy";
    else cout << "Unhappy";
}