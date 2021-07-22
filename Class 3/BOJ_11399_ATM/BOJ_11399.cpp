#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, input, result = 0;
    vector<int> time;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        cin >> input;
        time.push_back(input);
    }

    sort(time.begin(), time.end());

    for(int i = 0; i < N; i++){
        for(int j = 0; j <= i; j++)
            result += time[j];
    }
    cout << result;

}

